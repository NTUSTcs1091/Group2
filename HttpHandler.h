/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPHANDLER_H
#define _HTTPHANDLER_H

class HttpHandler {
public: 
    socket socket;
    
/**
 * @param input
 */
HttpPacket Handle(HttpPacket input);
protected: 
    
/**
 * @param socket
 */
void HttpHandler(socket socket);
};

#endif //_HTTPHANDLER_H