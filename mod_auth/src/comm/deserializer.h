#ifndef COMM_DESERIALIZER_H_
#define COMM_DESERIALIZER_H_

#include <nlohmann/json.hpp>
#include <string>

namespace auth {

class Deserializer {
 public:
  Deserializer();
  virtual ~Deserializer();
  static nlohmann::json ToJson(const std::string);
};

}

#endif
