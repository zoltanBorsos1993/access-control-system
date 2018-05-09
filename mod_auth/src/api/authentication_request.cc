#include "api/authentication_request.h"

#include <locale>
#include <stdexcept>

namespace auth {

void AuthenticationRequest::SetSecretHolder(SecretHolder* secret_holder) {
  secret_holder_ = secret_holder;
}

SecretHolder* AuthenticationRequest::GetSecretHolder() {
  return secret_holder_;
}

RequestMethod AuthenticationRequest::GetRequestMethod() {
  return request_method_;
}

void AuthenticationRequest::SetRequestMethod(std::string request_method) {
  // TODO: To uppercase method
  if (request_method == "AUTHENTICATE") {
    request_method_ = RequestMethod::AUTHENTICATE;
  } else if (request_method == "INFO") {
    request_method_ = RequestMethod::INFO;
  } else {
    throw std::runtime_error("Invalid method requested from AUTH: '" + request_method + "'.\n");
  }
}
}
