#ifndef API_AUTHENTICATION_REQUEST_H_
#define API_AUTHENTICATION_REQUEST_H_

#include <string>
#include <array>
#include <inttypes.h>
#include <service/secret_holder.h>


namespace auth {

enum class RequestMethod {
  AUTHENTICATE,
  INFO
};

class AuthenticationRequest {

 public:
  void SetSecretHolder(SecretHolder*);
  SecretHolder* GetSecretHolder();
  RequestMethod GetRequestMethod();
  void SetRequestMethod(std::string);

 private:
  SecretHolder* secret_holder_;
  RequestMethod request_method_;
};
}

#endif
