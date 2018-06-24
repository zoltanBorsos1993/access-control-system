#include "comm/network/zmq_handler.h"

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
  printf("Okay, main function has been called.\n");
  printf("Hello... ehrm, I dunno you. :(\n");
  // printf("Greetings juries and visitors, welcome to my thesis defence and presentation!\n");
  // printf("HELLO WORLD #1!\n");
  // printf("HELLO WORLD #2!\n");
  // printf("HELLO WORLD #3!\n");
  std::signal(SIGINT, int_handler);

  setbuf(stdout, NULL);

  printf("AUTH module starting...\n");

  printf("Start networking...\n");
  std::thread networking(StartNetworking);
  networking.join();

  usleep(3E6);
  // while (Not every component/thread started == true) {}

  printf("AUTH module started!\n");
}
