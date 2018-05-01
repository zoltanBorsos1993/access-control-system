#include "api/authentication_api.h"
#include "service/user_password/credential_validator_user_password.h"
#include "service/user_password/user_password.h"
#include "service/user_password/secret_holder_user_password.h"


namespace auth {

AuthenticationResponse& AuthenticationApi::authenticate(AuthenticationRequest& request) {
  CredentialStore* credential_store = CredentialValidatorUserPassword::GetInstance();
  UserPassword secret = UserPassword("john_doe", "secret");

  SecretHolder* secret_holder = new SecretHolderUserPassword(&secret);

  if (credential_store->IsValid(secret_holder)) {
    return GenerateSuccessfullResult(request);
  } else {
    return GenerateFailureResult(request);
  }

}

AuthenticationResponse& AuthenticationApi::GenerateSuccessfullResult(AuthenticationRequest& request) {
  printf("Authentication: success!\n");
  AuthenticationResponse response = AuthenticationResponse();
  return response;
}

AuthenticationResponse& AuthenticationApi::GenerateFailureResult(AuthenticationRequest& request) {
  printf("Authentication: failure!\n");
  AuthenticationResponse response = AuthenticationResponse();
  return response;
}
}
