//
// Created by nili  and shiraz on 1/8/20.
//

#include <strings.h>
#include "MySerialServer.h"
static int socketfd;
/**
 * The function start the server socket and bind.
 */
void MySerialServer::start(int* sock, socklen_t * client_length, ClientHandler *client_handler) {
  //while loop accepting and handeling clients serialy.
  dealWithClients(sock, client_length, client_handler);
}
/**
 * The function listen and accept a client in a loop until the time is up.
 */
void MySerialServer::dealWithClients(int* sock, socklen_t * client_length, ClientHandler *client_handler) {
  while (true) {
    struct timeval tv;
    struct sockaddr client1 = *((struct sockaddr*) client_length);
    socklen_t client_length1 = *client_length;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    int client_socket_in = accept(*sock, &client1, &client_length1);
    fd_set rfds;
    tv.tv_usec = 0.0;
    FD_ZERO(&rfds);
    FD_SET(client_socket_in, &rfds);
    int recVal = 0;
    tv.tv_sec = TIME_OUT;
    //checks timeout
    recVal = select(client_socket_in + 1, &rfds, NULL, NULL, &tv);
    switch (recVal) {
      //timeout
      case (0): {
        cout << "time_out" << endl;
        return;
      }//error
      case (-1): {
        cerr << "Error accepting client" << endl;
        exit(1);
      }default: {
        break;
      }
    }
    client_handler->handleClient(client_socket_in);
    close(client_socket_in);
  }
}
/**
 * The function opens a server socket on a new thread.
 */
void MySerialServer::open(int port, ClientHandler *client_handler) {
  //open socket
  //sockaddr_in address;
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    cerr << "Could not create a socket" << endl;
    exit(1);
  }
  struct sockaddr_in address, client_address;
  bzero((char*)&address, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "Could not bind the socket to an IP" << endl;
    exit(1);
  }
  if (listen(socketfd, 1) == -1) {
    cerr << "Error during listening command" << endl;
    exit(1);
  } else {
    cout << "Server is now listening..." << endl;
  }
  socklen_t client_lenght = sizeof(client_address);
  int* sockfd_ptr = &socketfd;
  socklen_t * client_ptr = &client_lenght;
  start(sockfd_ptr, client_ptr, client_handler);
  stop();
}
/**
 * The function closes the server socket.
 */
void MySerialServer::stop() {
  cout<<"closing the server socket"<<endl;
  close(socketfd);
}
