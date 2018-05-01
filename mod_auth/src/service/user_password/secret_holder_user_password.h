#ifndef SERVICE_USER_PASSWORD_SECRET_HOLDER_USER_PASSWORD_H_
#define SERVICE_USER_PASSWORD_SECRET_HOLDER_USER_PASSWORD_H_

#include <service/user_password/user_password.h>
#include "service/secret_holder.h"
#include <string>

namespace auth {
class SecretHolderUserPassword : public SecretHolder {
 public:
  SecretHolderUserPassword(UserPassword*);
  const std::string* GetSecret();

 private:
  const std::string* secret_;
};
}

#endif

