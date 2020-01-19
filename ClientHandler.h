//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
#include <fstream>
#define LINE_SIZE 1024
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int client_socket_in) = 0;
    virtual ~ClientHandler() = default;
};
#endif //EX4_CLIENTHANDLER_H
