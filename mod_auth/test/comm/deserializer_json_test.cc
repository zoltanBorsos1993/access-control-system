#include "comm/ser_des/ser_des_factory.h"
#include "service/user_password/secret_holder_user_password.h"

#include <gtest/gtest.h>

#include <string>

namespace auth {

TEST(SerDes, DeserializeUserPasswordAuthentication) {
  std::string authentication_request_str_json = R"(
    {
     "module": "auth",
     "method": "AUTHENTICATE",
     "data": {
      "username": "john_doe",
      "password": "secret"
     }
    }
  )";

  SerDes* ser_des = SerDesFactory::GetJsonSerDes();
  AuthenticationRequest request = ser_des->Deserialize(authentication_request_str_json);
}
}

//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
