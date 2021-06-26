// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "RequestParser.h"

/**
 * RequestParser implementation
 */

RequestParser::RequestParser() : state(init), content_size(0) {}

void RequestParser::reset() { state = init; }

template <typename InputIterator>
std::tuple<RequestParser::parse_result, InputIterator> RequestParser::Parse(
    HttpRequestPacket* HttpRequestPacket, InputIterator begin,
    InputIterator end) {
  while (begin != end) {
    parse_result result = consume(HttpRequestPacket, *begin++);
    if (result == success || result == fail)
      return std::make_tuple(result, begin);
  }
  return std::make_tuple(indeterminate, begin);
}

bool RequestParser::IsChar(int c) { return c >= 0 && c <= 127; }

bool RequestParser::IsCtl(int c) { return (c >= 0 && c <= 31) || (c == 127); }

bool RequestParser::IsDigit(int c) { return c >= '0' && c <= '9'; }

bool RequestParser::IsTspecial(int c) {
  switch (c) {
    case '(':
    case ')':
    case '<':
    case '>':
    case '@':
    case ',':
    case ';':
    case ':':
    case '\\':
    case '"':
    case '/':
    case '[':
    case ']':
    case '?':
    case '=':
    case '{':
    case '}':
    case ' ':
    case '\t':
      return true;
    default:
      return false;
  }
}

// Here is a state machine for http request parser
//
// The structure of http request should be expected as:
// GET /view HTTP/1.1\r\n
// Content-Type: text/plain;charset=utf-8\r\n
// Content-Length: 4\r\n
// Connection: close\r\n
// \r\n
// test
//
// If the input character is not valid, will return fail
// If the parse process is finished, will return success
// If the input character is valid but parse process is not finished, will
// return indeterminate
RequestParser::parse_result RequestParser::consume(
    HttpRequestPacket* httpRequestPacket, char input) {
  switch (state) {
    case init:
      if (!IsChar(input) || IsCtl(input) || IsTspecial(input)) {
        return fail;
      } else {
        state = method;
        httpRequestPacket->method.push_back(input);
        return indeterminate;
      }
    case method:
      if (input == ' ') {
        state = path;
        return indeterminate;
      } else if (!IsChar(input) || IsCtl(input) || IsTspecial(input)) {
        return fail;
      } else {
        httpRequestPacket->method.push_back(input);
        return indeterminate;
      }
    case path:
      if (input == ' ') {
        state = protocol_h;
        return indeterminate;
      } else if (IsCtl(input)) {
        return fail;
      } else {
        httpRequestPacket->path.push_back(input);
        return indeterminate;
      }
    case protocol_h:
      if (input == 'H') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_ht;
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_ht:
      if (input == 'T') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_htt;
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_htt:
      if (input == 'T') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_http;
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_http:
      if (input == 'P') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_slash;
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_slash:
      if (input == '/') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_version_major;
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_version_major:
      if (input == '.') {
        httpRequestPacket->protocol.push_back(input);
        state = protocol_version_minor;
        return indeterminate;
      } else if (IsDigit(input)) {
        httpRequestPacket->protocol.push_back(input);
        return indeterminate;
      } else {
        return fail;
      }
    case protocol_version_minor:
      if (input == '\r') {
        state = new_line_1;
        return indeterminate;
      } else if (IsDigit(input)) {
        httpRequestPacket->protocol.push_back(input);
        return indeterminate;
      } else {
        return fail;
      }
    case new_line_1:
      if (input == '\n') {
        state = header_start;
        return indeterminate;
      } else {
        return fail;
      }
    case header_start:
      if (input == '\r') {
        state = new_line_3;
        return indeterminate;
      } else if (!httpRequestPacket->headers.empty() &&
                 (input == ' ' || input == '\t')) {
        state = header_lws;
        return indeterminate;
      } else if (!IsChar(input) || IsCtl(input) || IsTspecial(input)) {
        return fail;
      } else {
        header_name_tmp.clear();
        header_value_tmp.clear();
        header_name_tmp.push_back(input);
        state = header_name;
        return indeterminate;
      }
    case header_lws:
      if (input == '\r') {
        state = new_line_2;
        return indeterminate;
      } else if (input == ' ' || input == '\t') {
        return indeterminate;
      } else if (IsCtl(input)) {
        return fail;
      } else {
        state = header_value;
        header_value_tmp.push_back(input);
        return indeterminate;
      }
    case header_name:
      if (input == ':') {
        state = space_before_header_value;
        return indeterminate;
      } else if (!IsChar(input) || IsCtl(input) || IsTspecial(input)) {
        return fail;
      } else {
        header_name_tmp.push_back(input);
        return indeterminate;
      }
    case space_before_header_value:
      if (input == ' ') {
        state = header_value;
        return indeterminate;
      } else {
        return fail;
      }
    case header_value:
      if (input == '\r') {
        httpRequestPacket->headers[header_name_tmp] = header_value_tmp;
        if (header_name_tmp.compare("Content-Length")) {
          content_size = atoi(header_value_tmp.c_str());
        }
        state = new_line_2;
        return indeterminate;
      } else if (IsCtl(input)) {
        return fail;
      } else {
        header_value_tmp.push_back(input);
        return indeterminate;
      }
    case new_line_2:
      if (input == '\n') {
        state = header_start;
        return indeterminate;
      } else {
        return fail;
      }
    case new_line_3:
      if (content_size == 0) {
        return (input == '\n') ? success : fail;
      } else {
        state = content;
      }
    case content:
      --content_size;
      httpRequestPacket->content.push_back(input);
      return (input == '\n') ? success : indeterminate;
    default:
      return fail;
  }
}
