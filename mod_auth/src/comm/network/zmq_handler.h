#ifndef COMM_NETWORK_ZMQ_HANDLER_H_
#define COMM_NETWORK_ZMQ_HANDLER_H_

#include <comm/network/network_handler.h>

namespace auth {

class ZmqHandler : public NetworkHandler {
 public:
  static NetworkHandler* GetInstance();
  void Start();
  void SendMessage(std::string message, Module module);

 private:
  ZmqHandler();
  virtual ~ZmqHandler();
  void SetupNetworking();
  void StartZmqServer();
  static ZmqHandler* impl_instance;
};

}

#endif
