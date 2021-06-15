// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include <gtest/gtest.h>

#include "RequestParser.h"
#include "HttpRequestPacket.h"

// TEST(RequestParserTest, ValidRequest) {
TEST(RequestParserTest, ValidRequest) {
  HttpRequestPacket packet;
  RequestParser parser;

  char test_request[] =
      "POST /addItem HTTP/1.1\r\n"
      "Content-Type: text/plain; "
      "charset=utf-8\r\n"
      "Content-Length: 4\r\n"
      "Connection: close\r\n"
      "\r\n"
      "test";

  RequestParser::parse_result result;
  std::tie(result, std::ignore) =
      parser.Parse(&packet, test_request, test_request + 20);
  EXPECT_EQ(RequestParser::parse_result::indeterminate, result);

  std::tie(result, std::ignore) = parser.Parse(
      &packet, test_request + 20, test_request + strlen(test_request));
  EXPECT_EQ(RequestParser::parse_result::success, result);

  EXPECT_EQ("POST", packet.method);
  EXPECT_EQ("/addItem", packet.path);
  EXPECT_EQ("HTTP/1.1", packet.protocol);
  EXPECT_EQ("text/plain; charset=utf-8", packet.headers["Content-Type"]);
  EXPECT_EQ("4", packet.headers["Length-Type"]);
  EXPECT_EQ("close", packet.headers["Connection"]);
  EXPECT_EQ("test", packet.content);
}

TEST(RequestParserTest, InvalidRequest) {
  HttpRequestPacket packet;
  RequestParser parser;

  char test_request[] =
      "POST /addItem HTTP/1.1\r\n"
      "Content-Type:text/plain; charset=utf-8\r\n"
      "Content-Length:4\r\n"
      "Connection:close\r\n"
      "\r\n"
      "test";

  RequestParser::parse_result result;
  std::tie(result, std::ignore) =
      parser.Parse(&packet, test_request, test_request + strlen(test_request));
  EXPECT_EQ(RequestParser::parse_result::fail, result);
}
