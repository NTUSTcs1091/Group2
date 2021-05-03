/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPRESPONSEPACKET_H
#define _HTTPRESPONSEPACKET_H

#include "HttpPacket.h"

#include <string>
#include <vector>

 // Encapsulate http response packets.
class HttpResponsePacket: public HttpPacket {
public: 
    std::string protocol;
    int status_code;
    
/**
 * @param response
 */
static std::vector<char> GetBytes(HttpResponsePacket response);
};

#endif //_HTTPRESPONSEPACKET_H