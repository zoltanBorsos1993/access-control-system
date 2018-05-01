#ifndef SERVICE_RFID_CREDENTIAL_STORE_RFID_H_
#define SERVICE_RFID_CREDENTIAL_STORE_RFID_H_

#include "service/credential_store.h"
#include <array>
#include <inttypes.h>
#include <service/secret_holder.h>

namespace auth {

class CredentialStoreRfid : public CredentialStore {
 private:
  CredentialStoreRfid();
  static CredentialStore* instance_;

 public:
  const bool IsValid(SecretHolder*) override;
  static CredentialStore* GetInstance();
};
}

#endif
