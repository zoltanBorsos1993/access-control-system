#ifndef MOD_AUTH_DISPATCHER_H
#define MOD_AUTH_DISPATCHER_H

#include "comm/ser_des/ser_des.h"

namespace auth {

class Dispatcher {
 public:
  static Dispatcher* GetInstance();
  void* Dispatch(void*);

 private:
  Dispatcher();
  static Dispatcher *instance_;
  SerDes* ser_des_;
};

}

#endif //MOD_AUTH_DISPATCHER_H
