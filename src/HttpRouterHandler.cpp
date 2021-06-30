// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpRouterHandler.h"

#include "ViewRequestHandler.h"
#include "BuyRequestHandler.h"

/**
 * HttpRouterHandler implementation
 */

HttpRouterHandler* HttpRouterHandler::instance = nullptr;

HttpRouterHandler* HttpRouterHandler::GetInstance() {
  if (instance == nullptr) {
    instance = new HttpRouterHandler();
  }
  return instance;
}

void HttpRouterHandler::RouteHttpRequest(
    const HttpRequestPacket& http_request_packet,
    HttpResponsePacket* http_response_packet) {
  if (http_request_packet.path.compare("/view") == 1) {
    RequestHandler* request_handler = new ViewRequestHandler();
    request_handler->ProcessBusinessLogic(http_request_packet,
                                          http_response_packet);
  } else if (http_request_packet.path.compare("/buy") == 1) {
    RequestHandler* request_handler = new BuyRequestHandler();
    request_handler->ProcessBusinessLogic(http_request_packet,
                                          http_response_packet);
  } else {
    http_response_packet->status_code = HttpResponsePacket::not_found;
    http_response_packet->content = "{\"msg\":\"Resource not found\"}";
  }
}
