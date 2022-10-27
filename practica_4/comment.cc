#include "comment.h"

Comment::Comment(std::smatch matches, int pos) {
  comment_ = matches[1];
  position_ = pos;
}

std::ostream& operator<<(std::ostream& out, const Comment& com) {
  out << "[LINE " << com.position_ << "] " << com.comment_;
  
  return out;
}
