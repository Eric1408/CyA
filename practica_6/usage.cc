#include "usage.h"

void Usage(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "aqui falta algo amigo\n";
    exit(EXIT_FAILURE);
  }
}
