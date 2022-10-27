#pragma once

#include <iostream>
#include <regex>
#include <string>

class Loop {
 public:
  Loop(std::smatch, int);
  
  friend std::ostream& operator<<(std::ostream&, const Loop&);
 private:
  int position_;
  std::string type_;
};