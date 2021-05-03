/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPROUTERHANDLER_H
#define _HTTPROUTERHANDLER_H

#include "RequestHandler.h"
#include "HttpRequestPacket.h"

#include <boost\asio.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\bind.hpp>

#include <iostream>
#include <unordered_map>
#include <string>

// Assign the encapsulated http packets to the corresponding business logic request-handler for processing.
class HttpRouterHandler: public HttpHandler {

public: 
    /**
     * @param io_service
     */
    HttpRouterHandler(Asio::io_service& io_service)
        :HttpHandler(io_service)
    {}

    ~HttpRouterHandler();

public:

    void RouteHttpRequest(const HttpRequestPacket& httpPacket, const boost::system::error_code& error);

private:

    std::unordered_map<std::string, RequestHandler> RequestHandlers;
    
};

#endif //_HTTPROUTERHANDLER_H