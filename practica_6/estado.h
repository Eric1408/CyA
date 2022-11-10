#pragma once

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <map>

#include "simbolo.h"

class Estado {
 public:
  Estado(void) : final_{0}, transitions_{0}, next_{} {}  
  Estado(std::string);
  inline bool IsAcepted(void) const {return final_ == 1 ? true : false;}
  std::map<Simbolo, int> GetMap(void) const {return next_;}

  inline int GetNext(const Simbolo& i) const {return next_.at(i);}
  friend std::ostream& operator<<(std::ostream&, const Estado&);


 private:
  int final_;
  int transitions_;
  std::map<Simbolo, int> next_;
};

