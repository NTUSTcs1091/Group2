// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _SERVER_H
#define _SERVER_H

#include <string>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include "HttpRequestHandler.h"

// Responsible for receiving requests from customers and handing them to
// requesthandler for processing. Manage customer requests.
class Server {

public:
  // Initialize the server, establish an endpoint and wait for the connection
  Server(const boost::asio::io_service &io_service,
         const boost::asio::ip::tcp::endpoint &ep);

  ~Server();

public:
  typedef boost::shared_ptr<HttpRequestHandler> handler_ptr;

  // Setup server service
  void StartServer();

private:
  // Handle the requests sent by the client
  void HandleAccept(handler_ptr new_handler,
                    const boost::system::error_code &error);

private:
  // Interact with the I/O services of the OS
  boost::asio::io_service *io_service;
  // Listen for connection requests
  boost::asio::ip::tcp::acceptor acceptor;

  // The number of sessions currently connected to the server
  int session_count;
  // The list of HTTP session handlers
  std::unordered_map<int, handler_ptr> map_handler_list;
};

#endif //_SERVER_H