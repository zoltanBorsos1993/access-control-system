#include "comm/ser_des/ser_des_factory.h"
#include "api/authentication_api.h"

#include <stdexcept>
#include <cstdio>
#include <string>

namespace auth {

void Dispatch(std::string message) {
  SerDes* ser_des = SerDesFactory::GetJsonSerDes();

  AuthenticationRequest request = ser_des->Deserialize(message);
  RequestMethod method = request.GetRequestMethod();

  if (method == RequestMethod::AUTHENTICATE) {
    printf("'authentication' dispatched!");
    AuthenticationApi::GetInstance()->Authenticate(request);

  } else if (method == RequestMethod::INFO) {
    printf("'info' dispatched!");
    printf(AuthenticationApi::GetInstance()->Info().c_str());

  } else {
    char* error_message;
    sprintf(error_message, "mod_auth with invalid method called: %s", &method);

    throw std::invalid_argument(error_message);
  }
}
}
