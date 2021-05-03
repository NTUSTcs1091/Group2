/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPREQUESTHANDLER_H
#define _HTTPREQUESTHANDLER_H

#include <boost\asio.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\bind.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\enable_shared_from_this.hpp>

#include <iostream>
#include <unordered_map>
#include <string>

#include "HttpHandler.h"
#include "HttpRequestPacket.h"

#define	Asio boost::asio
#define TCP boost::asio::ip::tcp

typedef boost::shared_ptr<HttpRequestHandler> handler_ptr;

// Responsible for processing the request, receiving data from the buffer and encapsulating it into http packets.
class HttpRequestHandler : public HttpHandler {
public:

    /**
     * @param io_service
     * @param mapSessionList
     * @param count
     */
    HttpRequestHandler(Asio::io_service& io_service, std::unordered_map<int, handler_ptr>& mapHandlerList, int nCount)
        :mapHandlerList(mapHandlerList), nCount(nCount), HttpHandler(io_service)
    {}

    ~HttpRequestHandler();

public:

    TCP::socket& getSocket();
    void start();

private:

    void HandleHttpRequest(const boost::system::error_code& error);

private:

    std::unordered_map<int, handler_ptr>& mapHandlerList;
    int nCount;

};

#endif //_HTTPREQUESTHANDLER_H