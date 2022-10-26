#pragma once

#include <iostream>
#include <regex>
#include <string>

class Var {
 public:
  Var(void) : positon{0}, name{""}, type{""} {}
  Var(std::string, int);

  friend std::ostream& operator<<(std::ostream&, const Var&);

 private:
  int positon;
  std::string name;
  std::string type;
};