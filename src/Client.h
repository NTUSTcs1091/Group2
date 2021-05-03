/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _CLIENT_H
#define _CLIENT_H

#include <boost\asio.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\bind.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\enable_shared_from_this.hpp>
#include <iostream>

#define	Asio boost::asio
#define TCP boost::asio::ip::tcp

class Client {
public: 
    
/**
 * @param context
 */
void Client(io_context context);
    
void StartHandle();
    
void OnReceive();
private: 
    socket socket;
};

#endif //_CLIENT_H