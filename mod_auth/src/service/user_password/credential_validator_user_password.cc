#include <service/user_password/credential_validator_user_password.h>
#include <cstdlib>
#include <ctime>

namespace auth {

CredentialStore* CredentialValidatorUserPassword::instance_;

CredentialValidatorUserPassword::CredentialValidatorUserPassword() {

}

CredentialStore* CredentialValidatorUserPassword::GetInstance() {
  if (instance_ == NULL) {
    instance_ = new CredentialValidatorUserPassword;
  }
  return instance_;
}

const bool CredentialValidatorUserPassword::IsValid(SecretHolder* secret_holder) {
  srand(time(0));
  if ((rand() % 100) < 50) {
    is_valid_ = true;
  } else {
    is_valid_ = false;
  }

  return is_valid_;
}

}
