//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"

class MyClientHandler : public ClientHandler {
public:
    virtual void handleClient(istream input_stream, ostream output_stream);
    virtual ~MyClientHandler() = default;

};


#endif //EX4_MYCLIENTHANDLER_H
