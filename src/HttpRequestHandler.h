// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPREQUESTHANDLER_H
#define _HTTPREQUESTHANDLER_H

#include "HttpHandler.h"

#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>

#include "HttpRequestPacket.h"

// Responsible for processing the request, receiving data from the buffer and
// encapsulating it into http packets.
class HttpRequestHandler : public HttpHandler {

public:
  typedef boost::shared_ptr<HttpRequestHandler> handler_ptr;

  // Initialize a http request handler
  HttpRequestHandler(boost::asio::io_service &io_service,
                     std::unordered_map<int, handler_ptr> &mapHandlerList,
                     int nCount);

  ~HttpRequestHandler();

public:
  // Establish connection
  void start();

private:
  // Handle the http request from input stream
  void HandleHttpRequest(const boost::system::error_code &error);

private:
  // The list of HTTP session handlers
  std::unordered_map<int, handler_ptr> &mapHandlerList;
  // The key of current handler in mapHandlerList
  int nCount;
};

#endif //_HTTPREQUESTHANDLER_H
