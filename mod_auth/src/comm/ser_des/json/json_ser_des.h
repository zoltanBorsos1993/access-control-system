#ifndef COMM_SER_DES_JSON_JSON_SER_DES_H_
#define COMM_SER_DES_JSON_JSON_SER_DES_H_

#include <comm/ser_des/ser_des.h>

namespace auth {

class JsonSerDes : public SerDes {
 public:
  JsonSerDes();
  virtual ~JsonSerDes();
  AuthenticationRequest Deserialize(void*) override;
  void* Serialize(AuthenticationResponse*) override;
};

}

#endif
