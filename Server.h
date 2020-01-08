//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#include "ClientHandler.h"
using namespace std;

class Server {
public:
    virtual void open(int port, ClientHandler client_handler) = 0;
    virtual void stop() = 0;
};

#endif //EX4_SERVER_H
