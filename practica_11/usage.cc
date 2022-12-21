#include <cstdlib>

#include "usage.h"

/**
 * @brief Funcion usage 
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  //std::cout << "dentro\n";
  if (argc > 4 || argc == 1) {
    std::cout << kHelp;
    exit(EXIT_FAILURE);
  } else if (argc == 2 && std::string(argv[1]) == "--help") {
   // std::cout << "dentro1\n";
    std::cout << kExplain;
    exit(EXIT_SUCCESS);
  }
}
