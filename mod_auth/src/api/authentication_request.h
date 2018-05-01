#ifndef API_AUTHENTICATION_REQUEST_H_
#define API_AUTHENTICATION_REQUEST_H_

#include <string>
#include <array>
#include <inttypes.h>
#include <service/secret_holder.h>


namespace auth {

class AuthenticationRequest {

 public:
  void SetSecretHolder(SecretHolder*);
  SecretHolder* GetSecretHolder();

 private:
  SecretHolder* secret_holder_;
};
}

#endif
