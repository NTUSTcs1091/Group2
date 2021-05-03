/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */


#ifndef _CLIENTMANAGER_H
#define _CLIENTMANAGER_H

class ClientManager {
public: 
    thread_pool[] threadpool;
    
void HandleAccept();
private: 
    io_context context;
};

#endif //_CLIENTMANAGER_H