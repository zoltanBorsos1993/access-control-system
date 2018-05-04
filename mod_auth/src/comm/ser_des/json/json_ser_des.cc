#include "comm/ser_des/json/json_ser_des.h"
#include "comm/ser_des/json/converters.h"

#include <nlohmann/json.hpp>

#include <stdexcept>

namespace auth {

JsonSerDes::JsonSerDes() {
}

JsonSerDes::~JsonSerDes() {
}

AuthenticationRequest JsonSerDes::Deserialize(void* deserializable) {
//  nlohmann::json json = nlohmann::json::parse(deserializable);
//  AuthenticationRequest request = json.get<AuthenticationRequest>();
//  return request;
}

void* JsonSerDes::Serialize(AuthenticationResponse* serializable) {
  throw "Dunno how to throw correct exception.";
}

}
