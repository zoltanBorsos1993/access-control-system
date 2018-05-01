#include "api/authentication_request.h"

namespace auth {

void AuthenticationRequest::SetSecretHolder(SecretHolder* secret_holder) {
  secret_holder_ = secret_holder;
}

SecretHolder* AuthenticationRequest::GetSecretHolder() {
  return secret_holder_;
}
}
