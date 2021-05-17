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

#include <string>

#include <boost/asio.hpp>

#include "HttpPacket.h"

// Encapsulate http response packets.
class HttpResponsePacket : public HttpPacket {
public:
	HttpResponsePacket();

public:
  // The protocol of the http response
  std::string protocol;
  // The status code of the http response
  int status_code;

  // Serialize a http response packet into bytes
  static std::unique_ptr<std::string> GetBytes(const HttpResponsePacket &response);
  // Return a string representing the http packet
  std::string ToString();
};

#endif //_HTTPRESPONSEPACKET_H
