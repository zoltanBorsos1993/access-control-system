#include <api/authentication_response.h>

namespace auth {

AuthenticationResponse::AuthenticationResponse() {

}

AuthenticationResponse::AuthenticationResponse(std::vector<Message<std::string>>* messages, AuthenticationStatus status) {
  messages_ = messages;
  status_ = status;
}

AuthenticationResponse::~AuthenticationResponse() {
  // TODO Auto-generated destructor stub
}

}
