#include "comm/ser_des/ser_des_factory.h"
#include "comm/ser_des/json/json_ser_des.h"

namespace auth {

SerDesFactory::SerDesFactory() {
  // TODO Auto-generated constructor stub

}

SerDesFactory::~SerDesFactory() {
  // TODO Auto-generated destructor stub
}

SerDes* SerDesFactory::GetJsonSerDes() {
  return new JsonSerDes();
}

}
