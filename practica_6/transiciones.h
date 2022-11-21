#pragma once

#include <iostream>
#include <map>
#include <string>

#include "simbolo.h"
#include "estado.h"

class Transicion {
 public:
  
 private:
  std::map<Simbolo,Estado> next_;

};
