#include <iostream>
#include <list>
#include <vector>

#include "voraces.h"
#include "usage.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  float input{atof(argv[1])};
  Voraces monedas(input);

  return 0;
}