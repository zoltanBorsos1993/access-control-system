#include <comm/deserializer.h>

namespace auth {

Deserializer::Deserializer() {
}

Deserializer::~Deserializer() {
}

nlohmann::json Deserializer::ToJson(std::string deserializable) {
  return nlohmann::json::parse(deserializable);
}

}
