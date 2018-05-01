#ifndef SERVICE_CREDENTIAL_STORE_H_
#define SERVICE_CREDENTIAL_STORE_H_

#include <service/secret_holder.h>

namespace auth {

class CredentialStore {
 public:
  virtual const bool IsValid(SecretHolder*) = 0;

 protected:
  bool is_valid_;
};

}

#endif
