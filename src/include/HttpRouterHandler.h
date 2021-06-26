// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPROUTERHANDLER_H
#define _HTTPROUTERHANDLER_H

#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include "HttpHandler.h"
#include "HttpRequestPacket.h"
#include "HttpResponsePacket.h"
#include "RequestHandler.h"

// Assign the encapsulated http packets to the corresponding business logic
// request-handler for processing.
class HttpRouterHandler : public HttpHandler {
private:
  // Initialize HTTP request router singleton
  HttpRouterHandler();

public:
  // Get the singleton instance of HttpRouterHandler
  static HttpRouterHandler* GetInstance();

  // Distribute the http request packet to the corresponding handler
  void RouteHttpRequest(const HttpRequestPacket& http_request_packet,
                        HttpResponsePacket* http_response_packet);

private:
  typedef boost::shared_ptr<RequestHandler> handler_ptr;

  // Store all business request handler instances
  std::unordered_map<std::string, handler_ptr> map_request_handlers;
};

#endif  //_HTTPROUTERHANDLER_H
