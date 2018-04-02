#ifndef API_SECRET_HOLDER_H_
#define API_SECRET_HOLDER_H_

namespace auth {

template <class T>
class SecretHolder {
 public:
  SecretHolder(T* secret) {
    secret_ = secret;
  };

  virtual ~SecretHolder() {};

  virtual T* GetSecret() {
    return secret_;
  }

  virtual void SetSecret(T* secret) {
    secret_ = secret;
  }

 private:
  T* secret_ = nullptr;
};
}

#endif
