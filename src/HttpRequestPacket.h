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
  HttpRequestPacket();

public:
  // The method of the http request
  std::string method;
  // The url path of the http request
  std::string path;
  // The protocol of the http request
  std::string protocol;

  /// Result of parse.
  enum parse_result { success, fail };

  // Parse http pequest packet from the buffer
  // The enum return value is the result for parsing
  // The InputIterator return value indicates how much of the input has been
  // parsed
  template <typename InputIterator>
  std::tuple<parse_result, InputIterator> ParseBytes(InputIterator begin,
                                                     InputIterator end);
  // Return a string representing the http packet
  virtual std::string ToString() override;
};

#endif //_HTTPREQUESTPACKET_H
