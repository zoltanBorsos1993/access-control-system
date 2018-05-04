#ifndef COMM_SER_DES_SER_DES_H_
#define COMM_SER_DES_SER_DES_H_

#include "api/authentication_request.h"
#include "api/authentication_response.h"

#include <string>

namespace auth {

class SerDes {
 public:
  SerDes();
  virtual ~SerDes();
  virtual AuthenticationRequest Deserialize(void*) = 0;
  virtual void* Serialize(AuthenticationResponse*) = 0;
};

}

#endif
