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

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

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
  typedef boost::shared_ptr<RequestHandler> handler_ptr;

  // Get the singleton instance of HttpRouterHandler
  static HttpRouterHandler* GetInstance();

  // Distribute the http request packet to the corresponding handler
  void RouteHttpRequest(const HttpRequestPacket& request_packet,
                        HttpResponsePacket* response_packet);

private:
  // Store all business request handler instances
  std::unordered_map<std::string, handler_ptr> map_request_handlers;
};

#endif  //_HTTPROUTERHANDLER_H