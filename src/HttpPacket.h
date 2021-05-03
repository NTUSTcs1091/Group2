/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _HTTPPACKET_H
#define _HTTPPACKET_H

#include <unordered_map>
#include <string>

// Encapsulate http packets.
class HttpPacket {
public: 
    std::unordered_map<std::string, std::string> header;
    std::string body;
    
virtual std::string ToString() = 0;
};

#endif //_HTTPPACKET_H