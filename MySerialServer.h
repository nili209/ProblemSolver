//
// Created by nili on 1/8/20.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public Server {
public:
    virtual void open(int port, ClientHandler client_handler);
    virtual void stop();
    void start(int port);
};


#endif //EX4_MYSERIALSERVER_H
