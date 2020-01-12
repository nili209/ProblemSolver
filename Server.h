//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"

using namespace std;
namespace server_side {
class Server {
 public:
  virtual void open(int port, ClientHandler *client_handler) = 0;
  virtual void stop(int socketfd) = 0;
  virtual ~Server() = default;
};
}

#endif //EX4_SERVER_H
