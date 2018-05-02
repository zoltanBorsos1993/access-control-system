#ifndef COMM_SER_DES_SER_DES_FACTORY_H_
#define COMM_SER_DES_SER_DES_FACTORY_H_

#include "comm/ser_des/ser_des.h"

namespace auth {

class SerDesFactory {
 public:
  SerDesFactory();
  virtual ~SerDesFactory();
  static SerDes* GetJsonSerDes();
};

}

#endif
