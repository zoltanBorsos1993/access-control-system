#ifndef API_AUTHENTICATION_API_H_BAK2_
#define API_AUTHENTICATION_API_H_BAK2_

#include "api/authentication_request.h"
#include "api/authentication_response.h"

namespace auth {

class AuthenticationApi {
 public:
  static AuthenticationApi* GetInstance();
  AuthenticationResponse& Authenticate(AuthenticationRequest&);
  const std::string Info();

 private:
  AuthenticationApi();
  virtual ~AuthenticationApi();
  static AuthenticationApi* instance_;
  AuthenticationResponse& GenerateSuccessfullResult(AuthenticationRequest&);
  AuthenticationResponse& GenerateFailureResult(AuthenticationRequest&);
};
}

#endif
