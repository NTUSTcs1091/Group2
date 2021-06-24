// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "BuyRequestHandler.h"

/**
 * BuyRequestHandler implementation
 */

void BuyRequestHandler::ProcessBusinessLogic(
    const HttpRequestPacket& http_request_packet,
    HttpResponsePacket* http_response_packet) {
  std::string response_content = "{\"stock_name\":\"book\",\"stock_count\":2}";

  http_response_packet->content = response_content;
  http_response_packet->status_code = HttpResponsePacket::ok;
}
