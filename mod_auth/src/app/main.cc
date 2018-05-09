#include "comm/network/zmq_handler.h"

#include <zmq.hpp>

#include <string>
#include <cstdio>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <csignal>

void int_handler(int x) {
  std::cout << std::endl;
  printf("SIGINT received! Stopping AUTH module...\n");
  exit(x);
}

void StartNetworking() {
  auth::NetworkHandler *network_handler = auth::ZmqHandler::GetInstance();
  network_handler->Start();
}

int main() {
  std::signal(SIGINT, int_handler);

  printf("AUTH module starting...\n");

  printf("Start networking...\n");
  std::thread networking(StartNetworking);

  usleep(3E6);
  // while (Not every component/thread started == true) {}

  printf("AUTH module started!\n");

  std::cin.get();
}
