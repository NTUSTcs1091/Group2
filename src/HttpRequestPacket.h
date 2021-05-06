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

#include "HttpPacket.h"

#include <string>

// Encapsulate http request packets.
class HttpRequestPacket : public HttpPacket {
public:
  std::string method;
  std::string path;
  std::string protocol;

  /**
   * @param buffer
   */
  static HttpRequestPacket ParseBytes(std::vector<char> buffer);
};

#endif //_HTTPREQUESTPACKET_H
