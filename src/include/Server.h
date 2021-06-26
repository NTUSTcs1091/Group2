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
// This is a singleton class
class Server {
private:
  // Initialize the server, establish an endpoint and wait for the connection
  Server(const std::string& address, const uint16_t port,
         const std::size_t max_session_count,
         const std::size_t max_thread_count);

  ~Server();

public:
  // Get the singleton instance of Server
  static Server* GetInstance(const std::string& address, const uint16_t port,
                             const std::size_t max_session_count,
                             const std::size_t max_thread_count);

  // Avoid copying
  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

  // Release request handler
  static void ReleaseHandler(const size_t n_count);

private:
  typedef std::shared_ptr<HttpRequestHandler> handler_ptr;

  // Handle the requests sent by the client
  void HandleAccept(handler_ptr new_handler,
                    const boost::system::error_code& error);
  // Setup server service
  void AcceptOnce();
  // Run service
  void Run();

private:
  // Interact with the I/O services of the OS
  boost::asio::io_context io_context;
  // Listen for connection requests
  boost::asio::ip::tcp::acceptor acceptor;
  // The list of HTTP session handlers
  static std::unordered_map<std::size_t, handler_ptr> map_handler_list;

  // The number of sessions currently connected to the server
  std::size_t session_count;
  // The maximunm number of sessions
  std::size_t max_session_count;
  // The maximunm number of threads
  std::size_t max_thread_count;
};

#endif  //_SERVER_H
