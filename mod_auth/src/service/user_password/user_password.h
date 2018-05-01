#ifndef SERVICE_USER_PASSWORD_USER_PASSWORD_H_
#define SERVICE_USER_PASSWORD_USER_PASSWORD_H_

#include <string>

namespace auth {

class UserPassword {
 public:
  UserPassword(const std::string, const std::string);
  virtual ~UserPassword();
  const std::string GetUserName();
  const std::string GetPassword();

 private:
  const std::string username_;
  const std::string password_;
};

}

#endif
