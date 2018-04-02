#ifndef API_AUTHENTICATION_REQUEST_H_
#define API_AUTHENTICATION_REQUEST_H_

#include "api/secret_holder.h"
#include "api/message.h"

#include <string>
#include <array>
#include <inttypes.h>
#include <vector>


namespace auth {

class AuthenticationRequest {

 public:
  AuthenticationRequest() {};
  virtual ~AuthenticationRequest() {};

  virtual SecretHolder<std::array<uint8_t, 24>>* GetSecretHolder() {
    return secret_holder_;
  }

  virtual void SetSecretHolder(SecretHolder<std::array<uint8_t, 24>>* secret_holder) {
    secret_holder_ = secret_holder;
  }

  virtual std::vector<Message<std::string>>* GetMessages() {
    return messages_;
  }

  virtual void SetMessages(std::vector<Message<std::string>>* messages) {
    messages_ = messages;
  }

 private:
  SecretHolder<std::array<uint8_t, 24>>* secret_holder_;
  std::vector<Message<std::string>>* messages_;
};

}

#endif
