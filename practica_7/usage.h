#pragma once 

#include <cstdlib>
#include <iostream>
#include <string>

const std::string kHelp = "Este programa analiza cadenas pasadas pasadas por un fichero de texto, indicando si\n"
                          "son rechazadas o acpetadas por el automata (DFA o NFA)\n";
const std::string kUse = "Modo de empleo: ./p06_automata_simulator input.fa input.txt\n"
                        "Pruebe ’p06_automata_simulator --help’ para mas informacion.\n";
void Usage(int, char*[]);
