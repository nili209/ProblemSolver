//
// Created by nili  and shiraz on 1/8/20.
//

#include <netinet/in.h>
#include <iostream>
#include <stack>
#include <thread>
#include <chrono>
#include <strings.h>
#include "MyParallelServer.h"
struct threadData {
  int socket;
  ClientHandler *client_handler_thread;
};
static int socketfd;
/**
 * The function activate the next thread to handle it's client.
 */
void *startThreadClient(void *param) {
  auto data = (threadData *) param;
  data->client_handler_thread->handleClient(data->socket);
  delete data;
  return reinterpret_cast<void *>(1);
}
/**
 * The function opens the server socket and bind and listen.
 */
void MyParallelServer::open(int port, ClientHandler *client_handler) {
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
  if (listen(socketfd, 10) == -1) {
    cerr << "Error during listening command" << endl;
    exit(1);
  } else {
    cout << "Server is now listening..." << endl;
  }
  socklen_t client_length = sizeof(client_address);
  int* sockfd_ptr = &socketfd;
  socklen_t * client_ptr = &client_length;
  start(sockfd_ptr, client_ptr, client_handler);
}
/**
 * The function listen and accept multiple clients in a loop until the time is up.
 */
void MyParallelServer::start(int* sock, socklen_t * client_length, ClientHandler *client_handler) {
  while (true) {
    struct sockaddr client1 = *((struct sockaddr *) client_length);
    socklen_t client_length1 = *client_length;
    int sock1 = *sock;
    struct timeval tv;
    tv.tv_usec = 0.0;
    tv.tv_sec = TIME_OUT;
    setsockopt(sock1, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    while (true) {
      int client_socket_in = accept(sock1, &client1, &client_length1);
      if (client_socket_in < 0) {
          cout << "time_out" << endl;
          stop();
      }
      cout << "Client accepted" << endl;
      auto data = new params;
      data->sockfd = client_socket_in;
      data->client_handler_params = client_handler;
      pthread_t trid;
      if (pthread_create(&trid, nullptr, startThreadClient, data) > 0) {
        cerr << "Error creating thread" << endl;
        exit(1);
      }
      threads_stack.push(trid);
      setsockopt(sock1, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    }
  }
}
/**
 * The function finish activating the threads and closes the server socket.
 */
void MyParallelServer::stop() {
  while (!threads_stack.empty()) {
    pthread_join(threads_stack.top(), nullptr);
    threads_stack.pop();
  }
  close(socketfd);
  exit(0);
}
/**
 * Destructor.
 */
MyParallelServer::~MyParallelServer() {
  delete info;
}