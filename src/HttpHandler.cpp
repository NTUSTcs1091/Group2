// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#include "HttpHandler.h"

/**
 * HttpHandler implementation
 */

HttpHandler::HttpHandler(boost::asio::io_service& io_service) : socket(io_service) {
}


/**
 * @param input
 * @return HttpPacket
 */
HttpPacket HttpHandler::Handle(HttpPacket input) {
    return null;
}

/**
 * @param socket
 */
void HttpHandler::HttpHandler(socket socket) {

}