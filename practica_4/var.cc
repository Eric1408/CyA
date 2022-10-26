#include "var.h"

Var::Var(std::string input, int pos) {
  //std::regex expression("(int|double)\\s(\\w+)");
  std::regex expression("[^[:graph:]]int\\s(\\w+(\\s=\\s\\d+)?)");
  std::smatch matches;
  if (std::regex_search(input, matches, expression)) {
    //name = matches[1];
    type = matches[0];
    positon = pos;
  }
}

std::ostream& operator<<(std::ostream& out, const Var& input) {
  out << "[LINE " << input.positon << " ] " << input.type << " " << input.name;

  return out;
}