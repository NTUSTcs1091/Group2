/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, 
 * @version 0.0.1
 */


#ifndef _HTTPREQUESTPACKET_H
#define _HTTPREQUESTPACKET_H

#include "HttpPacket.h"


class HttpRequestPacket: public HttpPacket {
public: 
    string method;
    string path;
    string protocol;
    
/**
 * @param buffer
 */
static HttpRequestPacket ParseBytes(vector<byte> buffer);
};

#endif //_HTTPREQUESTPACKET_H