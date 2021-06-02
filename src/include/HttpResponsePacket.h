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

#include <boost/asio.hpp>
#include <string>

#include "HttpPacket.h"

// Encapsulate http response packets.
class HttpResponsePacket : public HttpPacket {
public:
  // The status of the http response
  enum status_type {
    ok = 200,
    created = 201,
    accepted = 202,
    no_content = 204,
    multiple_choices = 300,
    moved_permanently = 301,
    moved_temporarily = 302,
    not_modified = 304,
    bad_request = 400,
    unauthorized = 401,
    forbidden = 403,
    not_found = 404,
    internal_server_error = 500,
    not_implemented = 501,
    bad_gateway = 502,
    service_unavailable = 503
  };

  HttpResponsePacket();
  // Constract HttpResponsePacket via response status_code and content
  HttpResponsePacket(const std::string& content, const status_type status_code);

public:
  // The protocol of the http response
  std::string protocol;
  // The status code of the http response
  status_type status_code;

  // Serialize a http response packet into bytes
  std::unique_ptr<std::vector<boost::asio::const_buffer>> GetBytes();
  // Return a string representing the http packet
  virtual std::string ToString() override;
};

#endif  //_HTTPRESPONSEPACKET_H
