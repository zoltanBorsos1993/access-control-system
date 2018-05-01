#ifndef SERVICE_RFID_SECRET_HOLDER_RFID_H_
#define SERVICE_RFID_SECRET_HOLDER_RFID_H_

#include "service/secret_holder.h"

#include <array>
#include <inttypes.h>

namespace auth {
class SecretHolderRfid : public SecretHolder {
 public:
  SecretHolderRfid(std::array<uint8_t, 24>*);
  void SetSecret(std::array<uint8_t, 24>*);
  std::array<uint8_t, 24>* GetSecret();

 private:
  std::array<uint8_t, 24>* secret_;
};
}

#endif
