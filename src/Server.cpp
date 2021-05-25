// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "Server.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <thread>

/**
 * Server implementation
 */

Server::Server(const std::string &address, const uint16_t port,
               const std::size_t max_session_count,
               const std::size_t max_thread_count)
    : acceptor(io_context),
      max_session_count(max_session_count),
      session_count(0),
      max_thread_count(max_thread_count) {
  // Open the acceptor with the option to reuse the address.
  boost::asio::ip::tcp::resolver resolver(io_context);
  boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve({address, port});
  acceptor.open(endpoint.protocol());
  acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
  acceptor.bind(endpoint);
  acceptor.listen();

  StartServer();
}

void Server::StartServer() {
  handler_ptr new_handler(
      new HttpRequestHandler(&io_context, &map_handler_list, session_count));
  ++session_count;

  acceptor.async_accept(*new_handler->GetSocket(),
                        boost::bind(&Server::HandleAccept, this, new_handler,
                                    boost::asio::placeholders::error));
}

void Server::Run() {
  if (max_thread_count > 1) {
    std::vector<std::shared_ptr<std::thread>> threads;
    for (std::size_t i = 0; i < max_thread_count; i++) {
      std::shared_ptr<std::thread> thread =
          std::make_shared<std::thread>([&]() { io_context.run(); });
      threads.push_back(thread);
    }
    for (auto &&thread : threads) {
      thread->join();
    }
  } else {
    io_context.run();
  }
}

void Server::HandleAccept(handler_ptr handler,
                          const boost::system::error_code &error) {
  if (!acceptor.is_open()) {
    return;
  }

  if (!error) {
    handler->Start();
  }

  StartServer();
}

Server::~Server() { std::cout << "Bye~" << std::endl; }