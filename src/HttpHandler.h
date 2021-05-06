// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _HTTPHANDLER_H
#define _HTTPHANDLER_H

#include <iostream>
#include <string>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>

#include "HttpPacket.h"

// Basic http handler class
class HttpHandler {
public:
  // Initialize a basic http handler
  HttpHandler(boost::asio::io_service &io_service);

public:
  // Return the socket instance
  boost::asio::ip::tcp::socket &getSocket();
  // Pre-process the request packet
  void Handle(HttpPacket &input);

protected:
  // Keep connected with the client-side
  boost::asio::ip::tcp::socket socket;
};

#endif //_HTTPHANDLER_H
