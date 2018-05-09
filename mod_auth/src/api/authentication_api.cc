#include "api/authentication_api.h"
#include "service/user_password/credential_validator_user_password.h"
#include "service/user_password/user_password.h"
#include "service/user_password/secret_holder_user_password.h"


namespace auth {

AuthenticationApi* AuthenticationApi::instance_ = new AuthenticationApi();

AuthenticationApi::AuthenticationApi() {}
AuthenticationApi::~AuthenticationApi() {}

AuthenticationApi* AuthenticationApi::GetInstance() {
  return instance_;
}

AuthenticationResponse& AuthenticationApi::Authenticate(AuthenticationRequest& request) {
  SecretHolder* secret_holder = request.GetSecretHolder();

  CredentialStore* credential_store = CredentialValidatorUserPassword::GetInstance();
  if (credential_store->IsValid(secret_holder)) {
    return GenerateSuccessfullResult(request);
  } else {
    return GenerateFailureResult(request);
  }
}

const std::string AuthenticationApi::Info() {
  return "mod_auth is alive! Version: 0.0.1";
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
