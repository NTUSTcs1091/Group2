// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPRESPONSEPACKET_H
#define _HTTPRESPONSEPACKET_H

#include "HttpPacket.h"

#include <string>

#include <boost/asio.hpp>

// Encapsulate http response packets.
class HttpResponsePacket : public HttpPacket {
public:
  // The protocol of the http response
  std::string protocol;
  // The status code of the http response
  int status_code;

  // Parse a http response packet into bytes
  static std::unique_ptr<char> GetBytes(const HttpResponsePacket &response);
};

#endif //_HTTPRESPONSEPACKET_H
