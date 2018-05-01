#ifndef API_AUTHENTICATION_RESPONSE_H_
#define API_AUTHENTICATION_RESPONSE_H_

#include "api/message.h"

#include <vector>

enum AuthenticationStatus {
  OK,
  WARNING,
  ERROR
};

namespace auth {

class AuthenticationResponse {
 public:
  AuthenticationResponse();
  AuthenticationResponse(std::vector<Message<std::string>>* messages, AuthenticationStatus status);
  virtual ~AuthenticationResponse();

  virtual std::vector<Message<std::string>>* GetMessages() {
    return messages_;
  }

  virtual void SetMessages(std::vector<Message<std::string>>* messages) {
    messages_ = messages;
  }

  virtual AuthenticationStatus GetStatus() {
    return status_;
  }

  virtual void SetStatus(AuthenticationStatus status) {
    status_ = status;
  }

 private:
  std::vector<Message<std::string>>* messages_;
  AuthenticationStatus status_;
};

}

#endif
