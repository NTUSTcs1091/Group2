// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _REQUESTHANDLER_H
#define _REQUESTHANDLER_H

#include "HttpHandler.h"
#include "HttpRequestPacket.h"
#include "HttpResponsePacket.h"

// Basic RequestHandler, father of business handlers
class RequestHandler {
public:
  RequestHandler();

public:
  // Business processing
  virtual void BusinessProcessing(const HttpRequestPacket& http_request_packet,
                                  HttpResponsePacket* http_response_packet) = 0;
};

#endif  //_REQUESTHANDLER_H
