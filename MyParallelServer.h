//
// Created by nili on 1/8/20.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "Server.h"
class MyParallelServer : public Server {
public:
    virtual void open(int port, ClientHandler client_handler);
    virtual void stop();
};


#endif //EX4_MYPARALLELSERVER_H
