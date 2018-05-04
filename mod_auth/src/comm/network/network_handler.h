#ifndef COMM_NETWORK_NETWORK_HANDLER_H_
#define COMM_NETWORK_NETWORK_HANDLER_H_

#include "app/modules.h"
#include "comm/ser_des/ser_des.h"
#include "comm/dispatcher/dispatcher.h"

#include <string>

namespace auth {

class NetworkHandler {
 public:
  virtual void Start() = 0;
  virtual void SendMessage(std::string, Module) = 0;

 protected:
  NetworkHandler();
  virtual ~NetworkHandler();
  Dispatcher* dispatcher_;
  static NetworkHandler* instance_;
};

}

#endif
