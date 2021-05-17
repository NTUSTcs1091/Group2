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

#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "HttpHandler.h"
#include "HttpRouterHandler.h"

// Responsible for processing the request, receiving data from the buffer and
// encapsulating it into http packets.
class HttpRequestHandler
    : public HttpHandler,
      public boost::enable_shared_from_this<HttpRequestHandler> {

public:
  typedef boost::shared_ptr<HttpRequestHandler> handler_ptr;

  // Initialize a http request handler
  HttpRequestHandler(boost::asio::io_service &io_service,
                     std::unordered_map<int, handler_ptr> &mapHandlerList,
                     int nCount);

  ~HttpRequestHandler();

public:
  // Establish connection
  void Start();
  // Terminate connection
  void Stop();

private:
  // Perform an asynchronous read operation
  void HandleRead();
  // Perform an asynchronous write operation
  void HandleWrite();

private:
  // The list of HTTP session handlers
  std::unordered_map<int, handler_ptr> &map_handler_list;
  // Ensure synchronization when reading/writing buffer
  boost::asio::io_service::strand strand;
  // The key of current handler in mapHandlerList
  int n_count;

  // The incoming request
  HttpRequestPacket httpRequestPacket;
  // The response to be sent back to the client
  HttpResponsePacket httpResponsePacket;

  // Assign parsed httppacket to the corresponding business handler
  HttpRouterHandler httpRouterHandler;
};

#endif //_HTTPREQUESTHANDLER_H
