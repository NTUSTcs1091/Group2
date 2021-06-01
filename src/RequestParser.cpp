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

template <typename InputIterator>
std::tuple<RequestParser::parse_result, InputIterator> RequestParser::Parse(
    HttpRequestPacket* HttpRequestPacket, InputIterator begin,
    InputIterator end) {
  while (begin != end) {
    parse_result result = consume(req, *begin++);
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

HttpRequestPacket::parse_result consume(HttpRequestPacket* HttpRequestPacket,
                                        char input) {
  // TODO
}