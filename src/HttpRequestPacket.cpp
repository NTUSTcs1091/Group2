// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpRequestPacket.h"

/**
 * HttpRequestPacket implementation
 */

namespace misc_strings {

const char name_value_separator[] = {':', ' '};
const char crlf[] = {'\r', '\n'};

}  // namespace misc_strings

std::string HttpRequestPacket::ToString() { 
  std::string return_str = "";
  return_str += method + ' ';
  return_str += path + ' ';
  return_str += protocol;
  return_str += misc_strings::crlf;
  for (const auto &header : headers) {
    return_str += header.first;
    return_str += misc_strings::name_value_separator;
    return_str += header.second;
    return_str += misc_strings::crlf;
  }
  return_str += misc_strings::crlf;
  return_str += content;
  return return_str;
}
