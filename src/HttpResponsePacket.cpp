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

constexpr char kOk[] = "HTTP/1.0 200 OK\r\n";
constexpr char kCreated[] = "HTTP/1.0 201 Created\r\n";
constexpr char kAccepted[] = "HTTP/1.0 202 Accepted\r\n";
constexpr char kNoContent[] = "HTTP/1.0 204 No Content\r\n";
constexpr char kMultipleChoices[] = "HTTP/1.0 300 Multiple Choices\r\n";
constexpr char kMovedPermanently[] = "HTTP/1.0 301 Moved Permanently\r\n";
constexpr char kMovedTemporarily[] = "HTTP/1.0 302 Moved Temporarily\r\n";
constexpr char kNotModified[] = "HTTP/1.0 304 Not Modified\r\n";
constexpr char kBadRequest[] = "HTTP/1.0 400 Bad Request\r\n";
constexpr char kUnauthorized[] = "HTTP/1.0 401 Unauthorized\r\n";
constexpr char kForbidden[] = "HTTP/1.0 403 Forbidden\r\n";
constexpr char kNotFound[] = "HTTP/1.0 404 Not Found\r\n";
constexpr char kInternalServerError[] =
    "HTTP/1.0 500 Internal Server Error\r\n";
constexpr char kNotImplemented[] = "HTTP/1.0 501 Not Implemented\r\n";
constexpr char kBadGateway[] = "HTTP/1.0 502 Bad Gateway\r\n";
constexpr char kServiceUnavailable[] = "HTTP/1.0 503 Service Unavailable\r\n";

static boost::asio::const_buffer to_buffer(
    HttpResponsePacket::status_type status) {
  switch (status) {
    case HttpResponsePacket::ok:
      return boost::asio::buffer(kOk);
    case HttpResponsePacket::created:
      return boost::asio::buffer(kCreated);
    case HttpResponsePacket::accepted:
      return boost::asio::buffer(kAccepted);
    case HttpResponsePacket::no_content:
      return boost::asio::buffer(kNoContent);
    case HttpResponsePacket::multiple_choices:
      return boost::asio::buffer(kMultipleChoices);
    case HttpResponsePacket::moved_permanently:
      return boost::asio::buffer(kMovedPermanently);
    case HttpResponsePacket::moved_temporarily:
      return boost::asio::buffer(kMovedTemporarily);
    case HttpResponsePacket::not_modified:
      return boost::asio::buffer(kNotModified);
    case HttpResponsePacket::bad_request:
      return boost::asio::buffer(kBadRequest);
    case HttpResponsePacket::unauthorized:
      return boost::asio::buffer(kUnauthorized);
    case HttpResponsePacket::forbidden:
      return boost::asio::buffer(kForbidden);
    case HttpResponsePacket::not_found:
      return boost::asio::buffer(kNotFound);
    case HttpResponsePacket::internal_server_error:
      return boost::asio::buffer(kInternalServerError);
    case HttpResponsePacket::not_implemented:
      return boost::asio::buffer(kNotImplemented);
    case HttpResponsePacket::bad_gateway:
      return boost::asio::buffer(kBadGateway);
    case HttpResponsePacket::service_unavailable:
      return boost::asio::buffer(kServiceUnavailable);
    default:
      return boost::asio::buffer(kInternalServerError);
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
      std::unique_ptr<std::vector<boost::asio::const_buffer>>(
          new std::vector<boost::asio::const_buffer>);
  buffers->push_back(status_strings::to_buffer(status_code));
  for (const auto &header : headers) {
    buffers->push_back(boost::asio::buffer(header.first));
    buffers->push_back(boost::asio::buffer(misc_strings::name_value_separator));
    buffers->push_back(boost::asio::buffer(header.second));
    buffers->push_back(boost::asio::buffer(misc_strings::crlf));
  }
  buffers->push_back(boost::asio::buffer(misc_strings::crlf));
  buffers->push_back(boost::asio::buffer(content));
  return buffers;
}
