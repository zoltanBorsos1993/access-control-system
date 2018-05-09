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
  auto data_p = (char*)deserializable;
  nlohmann::json json = nlohmann::json::parse(data_p);

  AuthenticationRequest request = json.get<AuthenticationRequest>();
  return request;
}

void* JsonSerDes::Serialize(AuthenticationResponse* serializable) {
  throw std::runtime_error("JSON 'Serialize' not yet implemented.");
}

}
