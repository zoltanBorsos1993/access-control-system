#include "comm/ser_des/json/converters.h"

#include "service/user_password/secret_holder_user_password.h"
#include "service/user_password/user_password.h"

namespace auth {

void from_json(const nlohmann::json& json, AuthenticationRequest& request) {
  std::string method = json.at("method").get<std::string>();
  request.SetRequestMethod(method);
  SecretHolder secret_holder = json.at("data").get<SecretHolder>();
  request.SetSecretHolder(&secret_holder);
}

void to_json(nlohmann::json& json, const AuthenticationRequest& request) {
}

void from_json(const nlohmann::json& json, SecretHolder& secret_holder) {
//  SecretHolderUserPassword& secret_holder_sub = (SecretHolderUserPassword&)secret_holder;
//  std::string* secret = new std::string(json.at("username").get<std::string>() + ":" + json.at("password").get<std::string>());
//  secret_holder_sub.SetSecret(secret);

//  secret_holder = json.get<SecretHolderUserPassword>();
}

void to_json(const nlohmann::json& json, SecretHolder& secret_holder) {
}

void from_json(const nlohmann::json& json, SecretHolderUserPassword& user_password_secret_holder) {
//  std::string* secret = new std::string(json.at("username").get<std::string>() + ":" + json.at("password").get<std::string>());
//  user_password_secret_holder.SetSecret(secret);
}

void to_json(const nlohmann::json& j, SecretHolderUserPassword& user_password_secret_holder) {
}
}
