//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <thread>
#include <netinet/in.h>
#include <iostream>

using namespace server_side;
class MySerialServer : public Server {
 public:
  virtual void open(int port, ClientHandler *client_handler);
  virtual void stop();
  void start(int* sock, socklen_t * client_length, ClientHandler *client_handler);
  //static void start(int port, ClientHandler *client_handler);
  static void dealWithClients(int* sock, socklen_t * client_length, ClientHandler *client_handler);
  virtual ~MySerialServer() = default;
};

#endif //EX4_MYSERIALSERVER_H
