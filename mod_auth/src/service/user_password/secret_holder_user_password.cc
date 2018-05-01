#include <service/user_password/secret_holder_user_password.h>

namespace auth {

SecretHolderUserPassword::SecretHolderUserPassword(UserPassword* secret_wrapper) {
  const std::string mangled = secret_wrapper->GetUserName() + ":" + secret_wrapper->GetPassword();
  this->secret_ = &mangled;
}

const std::string* SecretHolderUserPassword::GetSecret() {
  return this->secret_;
}

}
