/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, 
 * @version 0.0.1
 */


#ifndef _HTTPROUTERHANDLER_H
#define _HTTPROUTERHANDLER_H

#include "HttpHandler.h"


class HttpRouterHandler: public HttpHandler {
public: 
    unordered_map<string, RequestHanlder> RequestHandlers;
    
/**
 * @param socket
 */
void HttpRouterHandler(socket socket);
};

#endif //_HTTPROUTERHANDLER_H