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

HttpRouterHandler* HttpRouterHandler::GetInstance() {
  static HttpRouterHandler instance;
  return &instance;
}

void HttpRouterHandler::RouteHttpRequest(
    const HttpRequestPacket& http_request_packet,
    HttpResponsePacket* http_response_packet) {
  RequestHandler* request_handler;

  if (http_request_packet.path.compare("/view") == 1) {
    request_handler = new ViewRequestHandler();
  } else if (http_request_packet.path.compare("/buy") == 1) {
    request_handler = new BuyRequestHandler();
  } else {
    http_response_packet->status_code = HttpResponsePacket::not_found;
    http_response_packet->content = "{\"msg\":\"Resource not found\"}";
  }

  request_handler->ProcessBusinessLogic(http_request_packet,
                                        http_response_packet);
}
