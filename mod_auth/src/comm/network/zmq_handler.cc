#include <comm/network/zmq_handler.h>
#include "app/modules.h"

#include <zmq.hpp>
#include "comm/ser_des/json/json_ser_des.h"
#include <cstdio>

namespace auth {

NetworkHandler* NetworkHandler::instance_ = nullptr;
ZmqHandler* ZmqHandler::impl_instance = nullptr;

ZmqHandler::ZmqHandler() {
  dispatcher_ = nullptr;
}

ZmqHandler::~ZmqHandler() {
}

NetworkHandler* ZmqHandler::GetInstance() {
  if (instance_ == nullptr) {
    impl_instance = new ZmqHandler();
    instance_ = impl_instance;
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

    printf("Received data's via ZMQ...\n");

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
