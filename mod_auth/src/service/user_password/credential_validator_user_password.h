#ifndef SERVICE_USER_PASSWORD_CREDENTIAL_VALIDATOR_USER_PASSWORD_H_
#define SERVICE_USER_PASSWORD_CREDENTIAL_VALIDATOR_USER_PASSWORD_H_

#include "service/credential_store.h"

namespace auth {

class CredentialValidatorUserPassword : CredentialStore {
 private:
  CredentialValidatorUserPassword();
  static CredentialStore* instance_;

 public:
  static CredentialStore* GetInstance();
  const bool IsValid(SecretHolder*) override;
};

}

#endif
