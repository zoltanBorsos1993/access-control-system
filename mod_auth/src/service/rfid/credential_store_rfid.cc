#include <array>
#include <inttypes.h>
#include <service/rfid/credential_store_rfid.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace auth {

CredentialStore* CredentialStoreRfid::instance_;

CredentialStoreRfid::CredentialStoreRfid() {

}

CredentialStore* CredentialStoreRfid::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new CredentialStoreRfid;
  }
  return instance_;
}

const bool CredentialStoreRfid::IsValid(SecretHolder* secret_holder) {
  srand(time(0));
  if ((rand() % 100) < 50) {
    is_valid_ = true;
  } else {
    is_valid_ = false;
  }

  return is_valid_;
}
}
