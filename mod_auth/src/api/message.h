#ifndef API_MESSAGE_H_
#define API_MESSAGE_H_

#include <string>

namespace auth {

enum MessageStatus {
  SUCCESS,
  INFO,
  WARNING,
  ERROR
};

template <class T>
class Message {

 public:
//  Message();
  Message(T content, MessageStatus status) {
    content_ = content;
    status_ = status;
  }
  virtual ~Message() {};

  virtual T GetContent() {
    return content_;
  }

  virtual void SetContent(T content) {
    content_ = content;
  }

  virtual MessageStatus GetStatus() {
    return status_;
  }

  virtual void SetStatus(MessageStatus status) {
    status_ = status;
  }

  virtual bool IsOK() {
    if (status_ == MessageStatus::ERROR) {
      return false;
    }
    return true;
  }

 protected:
  T content_;
  MessageStatus status_;
};
}

#endif
