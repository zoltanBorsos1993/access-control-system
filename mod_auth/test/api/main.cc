#include "api/authentication_request.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace auth;
using namespace std;

array<uint8_t, 24> get_random_secret() {
  array<uint8_t, 24> secret = {0};
  for (int i = 0; i < 24; i++) {
     secret[i] = rand() % 128;
  }

  return secret;
}

int main(void) {
  array<uint8_t, 24> random_secret = get_random_secret();
  SecretHolder<array<uint8_t, 24>> secret_holder = SecretHolder<array<uint8_t, 24>>(&random_secret);

  vector<Message<string>> messages = vector<Message<string>>();
  messages.push_back(Message<string>("Foo message.", MessageStatus::SUCCESS));
  messages.push_back(Message<string>("Bar message.", MessageStatus::SUCCESS));
  messages.push_back(Message<string>("Baz message.", MessageStatus::SUCCESS));

  AuthenticationRequest req = AuthenticationRequest();
  req.SetSecretHolder(&secret_holder);
  req.SetMessages(&messages);

  cout << "Secret is: ";
  for (int i = 0; i < req.GetSecretHolder()->GetSecret()->size(); i++) {
    cout << to_string(req.GetSecretHolder()->GetSecret()->at(i)) << " ";
  }
  cout << endl;

  cout << "Messages are:" << endl;
  for (int i = 0; i < req.GetMessages()->size(); i++) {
    cout << "Message " << to_string(i) << ": ";
    cout << req.GetMessages()->at(i).GetContent() << endl;
  }

  return 0;
}
