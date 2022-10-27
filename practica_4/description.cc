#include "description.h"

Description::Description(std::smatch matches, int pos) {
  pos_ini_ = pos;
  descript_ = matches[0];
}

void Description::Build(std::smatch matches, int pos) {
  pos_ini_ = pos;
  descript_ = matches[0];
  descript_ += "\n";
}

void Description::Insert(std::smatch matches, int pos) {
  pos_end_ = pos;
  descript_ += matches[0];
}

void Description::Insert(std::smatch matches) {
  descript_ += matches[0];
  descript_ += "\n";
}

std::ostream& operator<<(std::ostream& out, const Description& descript) {
  out << descript.descript_;
  
  return out;
}
