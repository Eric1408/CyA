#include "usage.h"

void Usage(int argc, char* argv[]) {
  std::string help = "--help";

  if (argc < 3) {
    if (argc == 2 && argv[1] == help) {
      std::cout << kHelp;
      exit(EXIT_SUCCESS);
    }
    std::cout << kUse;
    exit(EXIT_FAILURE);
  } 
}
