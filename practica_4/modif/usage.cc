#include "usage.h"

/**
 * @brief Define como se debe usar el programa
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  std::string help = argv[1];
  if ((argc < 3 || argc > 3) && help != "--help") {
    std::cout << kHelp;
    exit(EXIT_SUCCESS);
  } 
  if (argc == 2 && help == "--help") {
    std::cout << kExplain;
    exit(EXIT_SUCCESS);
  }
}
