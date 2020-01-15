//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H
#include "Server.h"
#include <stack>
using namespace server_side;
class MyParallelServer : public Server {
 private:
  struct params {
    int sockfd;
    ClientHandler *client_handler_params;
  };
  stack<pthread_t> threads_stack;
  struct params *info = new params();
 public:
  MyParallelServer(){}
  virtual void open(int port, ClientHandler *client_handler);
  virtual void stop();
  void start(int socketfd, ClientHandler *client_handler, sockaddr_in address);
  virtual ~MyParallelServer(){delete info};
};

#endif //EX4_MYPARALLELSERVER_H
