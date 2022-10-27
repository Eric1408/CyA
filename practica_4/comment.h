#pragma once

#include <iostream>
#include <regex>
#include <string>

class Comment {
 public:
  Comment(std::smatch, int);

  friend std::ostream& operator<<(std::ostream&, const Comment&);
 private:
  int position_;
  std::string comment_;
};
