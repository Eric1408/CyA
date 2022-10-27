#pragma once

#include <iostream>
#include <regex>
#include <string>

class Var {
 public:
  Var(std::smatch, int);

  friend std::ostream& operator<<(std::ostream&, const Var&);

 private:
  int positon_;
  std::string name_;
  std::string type_;
};