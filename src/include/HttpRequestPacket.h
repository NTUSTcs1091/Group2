// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPREQUESTPACKET_H
#define _HTTPREQUESTPACKET_H

#include <string>

#include "HttpPacket.h"

// Encapsulate http request packets.
class HttpRequestPacket : public HttpPacket {
public:
  HttpRequestPacket();

public:
  // The method of the http request
  std::string method;
  // The url path of the http request
  std::string path;
  // The protocol of the http request
  std::string protocol;

  // Return a string representing the http packet
  virtual std::string ToString() override;
};

#endif  //_HTTPREQUESTPACKET_H
