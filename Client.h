/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _CLIENT_H
#define _CLIENT_H

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