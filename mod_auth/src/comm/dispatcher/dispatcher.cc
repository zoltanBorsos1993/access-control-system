#include "comm/dispatcher/dispatcher.h"
#include "comm/ser_des/ser_des_factory.h"
#include "api/authentication_api.h"

namespace auth {

Dispatcher::Dispatcher() {
  ser_des_ = SerDesFactory::GetJsonSerDes();
}

Dispatcher *Dispatcher::instance_;

Dispatcher* Dispatcher::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new Dispatcher();
  }
  return instance_;
}

void* Dispatcher::Dispatch(void* raw) {
  AuthenticationRequest request = ser_des_->Deserialize(raw);
  RequestMethod method = request.GetRequestMethod();

  AuthenticationResponse response;
  if (method == RequestMethod::AUTHENTICATE) {
    printf("'authentication' dispatched!\n");
    response = AuthenticationApi::GetInstance()->Authenticate(request);

  } else if (method == RequestMethod::INFO) {
    printf("'info' dispatched!\n");
    printf(AuthenticationApi::GetInstance()->Info().c_str());

  } else {
    char* error_message;
    sprintf(error_message, "mod_auth with invalid method called: %s", &method);

    throw std::invalid_argument(error_message);
  }

  return ser_des_->Serialize(&response);
}
}