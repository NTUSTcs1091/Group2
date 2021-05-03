/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _SERVER_H
#define _SERVER_H

#include <boost\asio.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\bind.hpp>

#include <iostream>
#include <unordered_map>
#include <string>

#include "HttpRequestHandler.h"

#define	Asio boost::asio
#define TCP boost::asio::ip::tcp

typedef boost::shared_ptr<HttpRequestHandler> handler_ptr;

// Responsible for receiving requests from customers and handing them to requesthandler for processing.
// Manage customer requests.
class Server {
public:

    /**
     * @param io_service
     * @param ed
     */
    Server(Asio::io_service& io_service, TCP::endpoint& ep)
        :io_service(io_service), acceptor(io_service, ep), sessionCount(0)
    {
        StartServer();
    }

    ~Server();

public:

    void StartServer();

private:
    void HandleAccept(handler_ptr new_handler, const boost::system::error_code& error);

private:

    Asio::io_service& io_service;
    TCP::acceptor acceptor;

    int sessionCount;
    std::unordered_map<int, handler_ptr> handlerList;

};

#endif //_SERVER_H