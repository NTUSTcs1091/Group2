// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpRequestHandler.h"

/**
 * HttpRequestHandler implementation
 */

HttpRequestHandler::HttpRequestHandler(
    boost::asio::io_service &io_service,
    std::unordered_map<int, handler_ptr> &mapHandlerList, int nCount)
    : mapHandlerList(mapHandlerList), nCount(nCount), HttpHandler(io_service) {}

/**
 * @param socket
 */
void HttpRequestHandler::HttpRequestHandler(socket socket) {}
