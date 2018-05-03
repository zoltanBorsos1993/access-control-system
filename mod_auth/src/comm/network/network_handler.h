#ifndef COMM_NETWORK_NETWORK_HANDLER_H_
#define COMM_NETWORK_NETWORK_HANDLER_H_

#include "app/modules.h"

#include <string>

namespace auth {

class NetworkHandler {
 public:
  virtual void Start() = 0;
  virtual void SendMessage(std::string, Module) = 0;

 protected:
  NetworkHandler();
  virtual ~NetworkHandler();
  static NetworkHandler* instance_;
};

}

#endif
