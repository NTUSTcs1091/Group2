// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpRequestHandler.h"

#include "HttpRouterHandler.h"

/**
 * HttpRequestHandler implementation
 */

HttpRequestHandler::HttpRequestHandler(boost::asio::io_context* io_context,
                                       Server* server, const int n_count)
    : n_count(n_count), strand(*io_context), HttpHandler(io_context) {
  this->server = server;
}

HttpRequestHandler::~HttpRequestHandler() {
  std::cout << n_count << ":~HandlerComplete" << std::endl;
}

void HttpRequestHandler::Start() { HandleRead(); }

void HttpRequestHandler::Stop() {
  socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
  socket.close();
  server->ReleaseHandler(n_count);
}

void HttpRequestHandler::HandleRead() {
  auto self(shared_from_this());
  socket.async_read_some(
      boost::asio::buffer(buffer),
      strand.wrap([this, self](std::error_code error,
                               std::size_t bytes_transferred) {
        if (!error) {
          RequestParser::parse_result result;
          std::tie(result, std::ignore) =
              request_parser.Parse(&http_request_packet, buffer.data(),
                                   buffer.data() + bytes_transferred);

          if (result == RequestParser::success) {
            HttpRouterHandler::GetInstance()->RouteHttpRequest(
                http_request_packet, &http_response_packet);
            HandleWrite();
          } else if (result == RequestParser::fail) {
            http_response_packet.status_code = HttpResponsePacket::bad_request;
            HandleWrite();
          } else {
            HandleRead();
          }
        }
      }));
}

void HttpRequestHandler::HandleWrite() {
  auto self(shared_from_this());
  boost::asio::async_write(
      socket, *http_response_packet.GetBytes(),
      strand.wrap([this, self](std::error_code error, std::size_t) {
        if (!error) {
          // Connection closure
          Stop();
        }
      }));
}
