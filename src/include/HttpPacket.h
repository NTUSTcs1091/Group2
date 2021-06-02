// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPPACKET_H
#define _HTTPPACKET_H

#include <string>
#include <unordered_map>

// Basic http packets class.
class HttpPacket {
public:
  HttpPacket();

public:
  // The header map of the http packet
  std::unordered_map<std::string, std::string> headers;
  // The content data of the http packet
  std::string content;

  // Return a string representing the http packet
  virtual std::string ToString() = 0;

  // Avoid copying
  HttpPacket(HttpPacket& cpy) = delete;
  HttpPacket& operator=(HttpPacket& cpy) = delete;
};

#endif  //_HTTPPACKET_H
