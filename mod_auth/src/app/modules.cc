#include "app/modules.h"

std::string ModuleName(Module module) {
  switch (module) {
    case Module::AUTH: return "AUTH";
    case Module::COMM: return "COMM";
    case Module::DATABASE: return "DATABASE";
    case Module::DRIVER: return "DRIVER";
  }
}
