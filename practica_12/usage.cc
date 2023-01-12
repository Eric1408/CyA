#include <cstdlib>

#include "usage.h"

/**
 * @brief Funcion usage 
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {

  if (argc == 1 || argc > 3) {
    std::cout << kHelp;
    exit(EXIT_FAILURE);
  } else if (argc == 2 && std::string(argv[1]) == "--help") {
   
    std::cout << kExplain;
    exit(EXIT_SUCCESS);
  }
}
