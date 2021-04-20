/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, 
 * @version 0.0.1
 */


#ifndef _HTTPREQUESTHANDLER_H
#define _HTTPREQUESTHANDLER_H

#include "HttpHandler.h"


class HttpRequestHandler: public HttpHandler {
public: 
    
/**
 * @param socket
 */
void HttpRequestHandler(socket socket);
};

#endif //_HTTPREQUESTHANDLER_H