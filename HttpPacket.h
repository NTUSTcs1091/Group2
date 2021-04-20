/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, 
 * @version 0.0.1
 */


#ifndef _HTTPPACKET_H
#define _HTTPPACKET_H

class HttpPacket {
public: 
    unordered_map<string, string> header;
    string body;
    
virtual string ToString() = 0;
};

#endif //_HTTPPACKET_H