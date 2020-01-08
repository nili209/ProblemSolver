//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
#include <fstream>
using namespace std;

class ClientHandler {
public:
    virtual void handleClient(istream input_stream, ostream output_stream) = 0;
};

#endif //EX4_CLIENTHANDLER_H
