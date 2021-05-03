/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPHANDLER_H
#define _HTTPHANDLER_H

#include <boost\asio.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\bind.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\enable_shared_from_this.hpp>

#include <iostream>
#include <unordered_map>
#include <string>

#include "HttpPacket.h"

#define	Asio boost::asio
#define TCP boost::asio::ip::tcp

class HttpHandler {
public:

    HttpHandler(Asio::io_service& io_service)
        :socket(io_service)
    {}

public:

    /**
     * @param input
     */
    HttpPacket Handle(HttpPacket input);

protected:

    TCP::socket socket;

};

#endif //_HTTPHANDLER_H