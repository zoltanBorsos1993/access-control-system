#include <comm/deserializer.h>

namespace auth {

Deserializer::Deserializer() {
  // TODO Auto-generated constructor stub

}

Deserializer::~Deserializer() {
  // TODO Auto-generated destructor stub
}

nlohmann::json Deserializer::ToJson(std::string deserializable) {
  return nlohmann::json::parse(deserializable);
}

}
