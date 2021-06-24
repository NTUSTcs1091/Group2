// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _BUYREQUESTHANDLER_H
#define _BUYREQUESTHANDLER_H

#include "RequestHandler.h"

// Handle purchase request, reduce inventory
class BuyRequestHandler : public RequestHandler {
public:
  BuyRequestHandler() = default;

public:
  // Handle buy request, manage the stock
  void ProcessBusinessLogic(const HttpRequestPacket& http_request_packet,
                          HttpResponsePacket* http_response_packet) override;
};

#endif  //_BUYREQUESTHANDLER_H
