//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
#include <fstream>
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int client_socket_in, int client_socket_out) = 0;
};
#endif //EX4_CLIENTHANDLER_H
