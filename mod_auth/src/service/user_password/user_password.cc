#include <service/user_password/user_password.h>

namespace auth {

UserPassword::UserPassword(const std::string username, const std::string password)
  : username_(username), password_(password) {}

UserPassword::~UserPassword() {
  // TODO Auto-generated destructor stub
}

const std::string UserPassword::GetUserName() {
  return username_;
}

const std::string UserPassword::GetPassword() {
  return password_;
}

}
