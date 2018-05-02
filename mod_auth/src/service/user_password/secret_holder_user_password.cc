#include <service/user_password/secret_holder_user_password.h>

namespace auth {

SecretHolderUserPassword::SecretHolderUserPassword() {
}

SecretHolderUserPassword::SecretHolderUserPassword(UserPassword* secret_wrapper) {
  const std::string mangled = secret_wrapper->GetUserName() + ":" + secret_wrapper->GetPassword();
  secret_ = &mangled;
}

const std::string* SecretHolderUserPassword::GetSecret() {
  return secret_;
}

void SecretHolderUserPassword::SetSecret(std::string* secret) {
  secret_ = secret;
}

}
