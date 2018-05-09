#include "comm/network/zmq_handler.h"
#include "comm/ser_des/json/json_ser_des.h"
#include "comm/dispatcher/dispatcher.h"
#include "app/modules.h"

#include <zmq.hpp>
#include <cstdio>

namespace auth {

NetworkHandler* NetworkHandler::instance_ = nullptr;

ZmqHandler::ZmqHandler() {
  dispatcher_ = Dispatcher::GetInstance();
}

ZmqHandler::~ZmqHandler() {
}

NetworkHandler* ZmqHandler::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new ZmqHandler();
  }
  return instance_;
}

void ZmqHandler::Start() {
  SetupNetworking();
}

void ZmqHandler::SetupNetworking() {
  printf("Configuring ZMQ as network handler...\n");

  StartZmqServer();
}

void ZmqHandler::StartZmqServer() {
  printf("Starting ZMQ server...\n");

  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);

  std::string bind_url = "tcp://*:9000";
  socket.bind(bind_url);

  printf("AUTH module ZMQ server listening on: %s\n", bind_url.c_str());
  while (true) {
    zmq::message_t request;

    socket.recv(&request);

    printf("Received data via ZMQ...\n");

    dispatcher_->Dispatch(request.data());

    zmq::message_t reply(3);
    memcpy(reply.data(), "OK!", 3);
    socket.send(reply);
  }
}

void ZmqHandler::SendMessage(std::string message, Module module) {
  printf("Message sent to %s...\n", ModuleName(module).c_str());
  printf("Content: %s\n", message.c_str());
}

}
