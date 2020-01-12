//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H
#include "Server.h"
using namespace server_side;
class MyParallelServer : public Server {
public:
    virtual void open(int port, ClientHandler* client_handler) = 0;
    virtual void stop() = 0;
    virtual ~MyParallelServer() = default;
};


#endif //EX4_MYPARALLELSERVER_H
