#ifndef COMM_SER_DES_JSON_CONVERTERS_H_
#define COMM_SER_DES_JSON_CONVERTERS_H_

#include "api/authentication_request.h"
#include "service/secret_holder.h"
#include "service/user_password/secret_holder_user_password.h"

#include <nlohmann/json.hpp>

namespace auth {
  void from_json(const nlohmann::json& json, AuthenticationRequest& request);
  void to_json(nlohmann::json& json, const AuthenticationRequest& request);

  void from_json(const nlohmann::json& json, SecretHolder& secret_holder);
  void to_json(nlohmann::json& json, const SecretHolder& secret_holder);

  void from_json(const nlohmann::json& json, SecretHolderUserPassword& user_password_secret_holder);
  void to_json(nlohmann::json& j, const SecretHolderUserPassword& user_password_secret_holder);
}

#endif
