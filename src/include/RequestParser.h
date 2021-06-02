// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _REQUESTPARSER_H
#define _REQUESTPARSER_H

#include <iostream>
#include <vector>

#include "HttpRequestPacket.h"

class RequestParser {
public:
  RequestParser();

public:
  // reset the parser
  void reset();

  // Result of parse.
  enum parse_result { success, fail, indeterminate };

  // Parse http pequest packet from the buffer
  // The enum return value is the result for parsing
  // The InputIterator return value indicates how much of the input has been
  // parsed
  template <typename InputIterator>
  std::tuple<parse_result, InputIterator> Parse(
      HttpRequestPacket* HttpRequestPacket, InputIterator begin,
      InputIterator end);

  // Avoid copying
  RequestParser(RequestParser& cpy) = delete;
  RequestParser& operator=(RequestParser& cpy) = delete;

private:
  // Handle the next character of input.
  parse_result consume(HttpRequestPacket* httpRequestPacket, char input);

  // Check if a byte is an HTTP character.
  static bool IsChar(int c);

  // Check if a byte is an HTTP control character.
  static bool IsCtl(int c);

  // Check if a byte is defined as an HTTP tspecial character.
  static bool IsTspecial(int c);

  // Check if a byte is a digit.
  static bool IsDigit(int c);

  // The current state of parser
  enum parser_state {
    init,
    method,
    path,
    protocol_h,
    protocol_ht,
    protocol_htt,
    protocol_http,
    protocol_slash,
    protocol_version_major_start,
    protocol_version_major,
    protocol_version_minor_start,
    protocol_version_minor,

    new_line_1,
    header_start,
    header_lws,
    header_name,
    space_before_header_value,
    header_value,
    new_line_2,
    new_line_3,
  } state;

  // Temporary storage of header name
  std::string header_name_tmp;
  // Temporary storage of header value
  std::string header_value_tmp;
};

#endif  //_REQUESTPARSER_H
