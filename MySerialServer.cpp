//
// Created by nili  and shiraz on 1/8/20.
//
#include <sstream>
#include <unistd.h>
#include <mutex>
#include <condition_variable>
#include "MySerialServer.h"

void MySerialServer::start(int port, ClientHandler *client_handler) {
  //open socket
  int socketfd;
  sockaddr_in address;
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    cerr << "Could not create a socket" << endl;
    exit(1);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "Could not bind the socket to an IP" << endl;
    exit(1);
  }
  //while loop accepting and handeling clients serialy.
  dealWithClients(client_handler, socketfd, address);
  close(socketfd);
}
void MySerialServer::dealWithClients(ClientHandler *client_handler, int socketfd, sockaddr_in &address) {
  while (true) {
    if (listen(socketfd, 5) == -1) {
      cerr << "Error during listening command" << endl;
      exit(1);
    } else {
      cout << "Server is now listening..." << endl;
    }
    cout << "nili" << endl;
    int client_socket_in = accept(socketfd, (struct sockaddr *) &address,
                                  (socklen_t *) &address);
    if (client_socket_in == -1) {
      cerr << "Error accepting client" << endl;
      exit(1);
    }
    cout << "shiraz" << endl;
    client_handler->handleClient(client_socket_in, client_socket_in);
    close(client_socket_in);
    //timeout
    return;
  }
}
void MySerialServer::open(int port, ClientHandler *client_handler) {
  thread thread_1(start, port, client_handler);
  thread_1.join();
}
void MySerialServer::stop(int socketfd) {

}
