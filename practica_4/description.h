#pragma once

#include <iostream>
#include <string>
#include <regex>

class Description {
 public:
  Description(void) : pos_ini_{0}, pos_end_{0}, descript_{""} {}
  Description(std::smatch, int);
  
  void Build(std::smatch, int);
  void Insert(std::smatch);
  void Insert(std::smatch, int);

  inline int GetInit(void) const {return pos_ini_;}
  inline int GetEnd(void) const {return pos_end_;} 

  friend std::ostream& operator<<(std::ostream&, const Description&);
 private:
  int pos_ini_;
  int pos_end_;
  std::string descript_;
};
