#include <service/rfid/secret_holder_rfid.h>

namespace auth {

SecretHolderRfid::SecretHolderRfid(std::array<uint8_t, 24>* secret) {
  secret_ = secret;
}

void SecretHolderRfid::SetSecret(std::array<uint8_t, 24>* secret) {
  secret_ = secret;
}

std::array<uint8_t, 24>* SecretHolderRfid::GetSecret() {
  return secret_;
}
}
