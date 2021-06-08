// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpResponsePacket.h"

/**
 * HttpResponsePacket implementation
 */

namespace status_strings {

const std::string ok = "HTTP/1.0 200 OK\r\n";
const std::string created = "HTTP/1.0 201 Created\r\n";
const std::string accepted = "HTTP/1.0 202 Accepted\r\n";
const std::string no_content = "HTTP/1.0 204 No Content\r\n";
const std::string multiple_choices = "HTTP/1.0 300 Multiple Choices\r\n";
const std::string moved_permanently = "HTTP/1.0 301 Moved Permanently\r\n";
const std::string moved_temporarily = "HTTP/1.0 302 Moved Temporarily\r\n";
const std::string not_modified = "HTTP/1.0 304 Not Modified\r\n";
const std::string bad_request = "HTTP/1.0 400 Bad Request\r\n";
const std::string unauthorized = "HTTP/1.0 401 Unauthorized\r\n";
const std::string forbidden = "HTTP/1.0 403 Forbidden\r\n";
const std::string not_found = "HTTP/1.0 404 Not Found\r\n";
const std::string internal_server_error =
    "HTTP/1.0 500 Internal Server Error\r\n";
const std::string not_implemented = "HTTP/1.0 501 Not Implemented\r\n";
const std::string bad_gateway = "HTTP/1.0 502 Bad Gateway\r\n";
const std::string service_unavailable = "HTTP/1.0 503 Service Unavailable\r\n";

static boost::asio::const_buffer to_buffer(
    HttpResponsePacket::status_type status) {
  switch (status) {
    case HttpResponsePacket::ok:
      return boost::asio::buffer(ok);
    case HttpResponsePacket::created:
      return boost::asio::buffer(created);
    case HttpResponsePacket::accepted:
      return boost::asio::buffer(accepted);
    case HttpResponsePacket::no_content:
      return boost::asio::buffer(no_content);
    case HttpResponsePacket::multiple_choices:
      return boost::asio::buffer(multiple_choices);
    case HttpResponsePacket::moved_permanently:
      return boost::asio::buffer(moved_permanently);
    case HttpResponsePacket::moved_temporarily:
      return boost::asio::buffer(moved_temporarily);
    case HttpResponsePacket::not_modified:
      return boost::asio::buffer(not_modified);
    case HttpResponsePacket::bad_request:
      return boost::asio::buffer(bad_request);
    case HttpResponsePacket::unauthorized:
      return boost::asio::buffer(unauthorized);
    case HttpResponsePacket::forbidden:
      return boost::asio::buffer(forbidden);
    case HttpResponsePacket::not_found:
      return boost::asio::buffer(not_found);
    case HttpResponsePacket::internal_server_error:
      return boost::asio::buffer(internal_server_error);
    case HttpResponsePacket::not_implemented:
      return boost::asio::buffer(not_implemented);
    case HttpResponsePacket::bad_gateway:
      return boost::asio::buffer(bad_gateway);
    case HttpResponsePacket::service_unavailable:
      return boost::asio::buffer(service_unavailable);
    default:
      return boost::asio::buffer(internal_server_error);
  }
}
}  // namespace status_strings

namespace misc_strings {

const char name_value_separator[] = {':', ' '};
const char crlf[] = {'\r', '\n'};

}  // namespace misc_strings

HttpResponsePacket::HttpResponsePacket() {
  headers["Connection"] = "Keep-Alive";
  headers["Content-Type"] = "application/json;charset=UTF-8";
}

std::unique_ptr<std::vector<boost::asio::const_buffer>>
HttpResponsePacket::GetBytes() {
  std::unique_ptr<std::vector<boost::asio::const_buffer>> buffers =
      std::make_unique<std::vector<boost::asio::const_buffer>>();
  buffers->push_back(status_strings::to_buffer(status_code));
  for (auto &header : headers) {
    buffers->push_back(boost::asio::buffer(header.first));
    buffers->push_back(boost::asio::buffer(misc_strings::name_value_separator));
    buffers->push_back(boost::asio::buffer(header.second));
    buffers->push_back(boost::asio::buffer(misc_strings::crlf));
  }
  buffers->push_back(boost::asio::buffer(misc_strings::crlf));
  buffers->push_back(boost::asio::buffer(content));
  return buffers;
}
