#ifndef COMM_SER_DES_SER_DES_H_
#define COMM_SER_DES_SER_DES_H_

#include "api/authentication_request.h"

#include <string>

namespace auth {

class SerDes {
 public:
  SerDes();
  virtual ~SerDes();
  virtual AuthenticationRequest Deserialize(std::string) = 0;
  virtual std::string Serialize(AuthenticationRequest) = 0;
};

}

#endif
