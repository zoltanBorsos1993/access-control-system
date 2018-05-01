#include "gtest/gtest.h"

#include "comm/deserializer.h"

#include <typeinfo>

TEST(Deserializer, FromStringToJson) {
  std::string serialized_user = R"(
    {
      "username": "zoltanb",
      "password": "secret"
    }
  )";

  nlohmann::json j = auth::Deserializer::ToJson(serialized_user);

  ASSERT_STREQ("zoltanb", j.at("username").get<std::string>().c_str());
  ASSERT_STREQ("secret", j.at("password").get<std::string>().c_str());

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
