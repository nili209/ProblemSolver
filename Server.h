//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H
#include <sstream>
#include <unistd.h>
#include <mutex>
#include "ClientHandler.h"
#define TIME_OUT 60
using namespace std;
namespace server_side {
class Server {
 public:
  virtual void open(int port, ClientHandler *client_handler) = 0;
  virtual void stop() = 0;
  virtual ~Server() = default;
};
}

#endif //EX4_SERVER_H
