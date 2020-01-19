//
// Created by nili  and shiraz on 1/8/20.
//

#include <netinet/in.h>
#include <iostream>
#include <stack>
#include <thread>
#include <chrono>
#include "MyParallelServer.h"
mutex mutex_lock;
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
}
/**
 * The function opens the server socket and bind and listen.
 */
void MyParallelServer::open(int port, ClientHandler *client_handler) {
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
  if (listen(socketfd, 10) == -1) {
    cerr << "Error during listening command" << endl;
    exit(1);
  } else {
    cout << "Server is now listening..." << endl;
  }
  start(client_handler, address);
}
/**
 * The function listen and accept multiple clients in a loop until the time is up.
 */
void MyParallelServer::start(ClientHandler *client_handler, sockaddr_in address) {
  while (true) {
    struct timeval tv;
    int client_socket_in = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    fd_set rfds;
    tv.tv_usec = 0.0;
    FD_ZERO(&rfds);
    FD_SET(client_socket_in, &rfds);
    tv.tv_sec = TIME_OUT;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    //checks timeout
    if (client_socket_in < 0) {
      if (errno == EWOULDBLOCK || errno == EAGAIN) {
        cout << "time_out" << endl;
        stop();
        break;
      }
      perror("accept");
      exit(1);
    }
    setsockopt(client_socket_in, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    auto data = new threadData;
    cout<<"Client accepted"<<endl;
    data->socket = client_socket_in;
    data->client_handler_thread = client_handler;
    pthread_t trid;
    if (pthread_create(&trid, nullptr, startThreadClient, data) > 0) {
      cerr << "Error creating thread" << endl;
      exit(1);
    }
    threads_stack.push(trid);
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
}
MyParallelServer::~MyParallelServer() {
  delete info;
}