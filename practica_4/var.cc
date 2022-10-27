#include "var.h"

Var::Var(std::smatch matches, int pos) {
  name_ = matches[2];
  if (matches[1] == "int") {
    type_ = "INT";
  } else {
    type_ = "DOUBLE";
  }
  positon_ = pos;
}

std::ostream& operator<<(std::ostream& out, const Var& input) {
  out << "[LINE " << input.positon_ << "] " << input.type_ << ": " << input.name_;

  return out;
}