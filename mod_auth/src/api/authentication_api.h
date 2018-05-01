#ifndef API_AUTHENTICATION_API_H_BAK2_
#define API_AUTHENTICATION_API_H_BAK2_

#include "api/authentication_request.h"
#include "api/authentication_response.h"

namespace auth {

class AuthenticationApi {
 public:
  static AuthenticationApi* GetInstance();
  AuthenticationResponse& Authenticate(AuthenticationRequest& request);
  const std::string Info();

 private:
  static AuthenticationApi* instance_;
  AuthenticationResponse& GenerateSuccessfullResult(AuthenticationRequest&);
  AuthenticationResponse& GenerateFailureResult(AuthenticationRequest&);
};
}

#endif
