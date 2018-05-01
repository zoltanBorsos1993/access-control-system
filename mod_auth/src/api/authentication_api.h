#ifndef API_AUTHENTICATION_API_H_BAK2_
#define API_AUTHENTICATION_API_H_BAK2_

#include "api/authentication_request.h"
#include "api/authentication_response.h"

namespace auth {

class AuthenticationApi {
 public:
  AuthenticationResponse& authenticate(AuthenticationRequest& request);

 private:
  AuthenticationResponse& GenerateSuccessfullResult(AuthenticationRequest&);
  AuthenticationResponse& GenerateFailureResult(AuthenticationRequest&);
};
}

#endif
