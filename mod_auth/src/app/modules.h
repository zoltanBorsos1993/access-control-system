#ifndef APP_MODULES_H_
#define APP_MODULES_H_

#include <string>

enum class Module {
  AUTH = 0,
  COMM = 1,
  DATABASE = 2,
  DRIVER = 3
};

std::string ModuleName(Module);

//class Module final {
// public:
//  static std::string AUTH;
//  static std::string COMM;
//  static std::string DATABASE;
//  static std::string DRIVER;
//};

#endif
