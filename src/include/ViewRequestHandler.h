// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _VIEWREQUESTHANDLER_H
#define _VIEWREQUESTHANDLER_H

#include "RequestHandler.h"

class ViewRequestHandler : public RequestHandler {
public:
  ViewRequestHandler();

public:
  // Handle view request, show inventory status
  void BusinessProcessing(const HttpRequestPacket& http_request_packet,
                          HttpResponsePacket* http_response_packet) override;
};

#endif  //_VIEWREQUESTHANDLER_H
