// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "Server.h"

/**
 * Server implementation
 */

Server::Server(boost::asio::io_service &io_service,
               boost::asio::ip::tcp::endpoint &ep)
    : io_service(io_service), acceptor(io_service, ep), sessionCount(0) {
  StartServer();
}
