/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, 
 * @version 0.0.1
 */


#ifndef _HTTPRESPONSEPACKET_H
#define _HTTPRESPONSEPACKET_H

#include "HttpPacket.h"


class HttpResponsePacket: public HttpPacket {
public: 
    string protocol;
    int status_code;
    
/**
 * @param response
 */
static vector<byte> GetBytes(HttpResponsePacket response);
};

#endif //_HTTPRESPONSEPACKET_H