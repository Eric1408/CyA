#include "loop.h"

Loop::Loop(std::smatch matches, int pos) {
  type_ = matches[1];
  position_ = pos;
}


std::ostream& operator<<(std::ostream& out, const Loop& input) {
  out << "[LINE " << input.position_ << "] LOOP: " << input.type_;

  return out;
}
