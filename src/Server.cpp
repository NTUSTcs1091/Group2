// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "Server.h"

#include <thread>

#include <boost/bind.hpp>

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
  boost::asio::ip::address add;
  boost::asio::ip::tcp::endpoint endpoint(add.from_string(address), port);
  acceptor.open(endpoint.protocol());
  acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
  acceptor.bind(endpoint);
  acceptor.listen();

  AcceptOnce();
}

Server::~Server() { std::cout << "Bye~" << std::endl; }

void Server::AcceptOnce() {
  handler_ptr new_handler(
      new HttpRequestHandler(&io_context, this, session_count));
  ++session_count;

  acceptor.async_accept(
      *new_handler->GetSocket(),
      boost::bind(&Server::HandleAccept, this, new_handler.release(),
                  boost::asio::placeholders::error));
}

void Server::Run() {
  std::vector<std::shared_ptr<std::thread>> threads;
  for (std::size_t i = 0; i < max_thread_count; i++) {
    std::shared_ptr<std::thread> thread =
        std::make_shared<std::thread>([this]() { this->io_context.run(); });
    threads.push_back(thread);
  }
  for (auto &&thread : threads) {
    thread->join();
  }
}

void Server::HandleAccept(handler_ptr handler,
                          const boost::system::error_code &error) {
  if (!acceptor.is_open()) {
    return;
  }
  if (!error) {
    handler->Start();
    map_handler_list.insert(std::make_pair(handler->n_count, handler));
  }
  AcceptOnce();
}

void Server::ReleaseHandler(const size_t n_count) {
  auto it = map_handler_list.find(n_count);
  map_handler_list.erase(it);
}
