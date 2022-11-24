#pragma once 

#include <cstdlib>
#include <iostream>
#include <string>

const std::string kHelp = "Este programa analiza la gramatica pasada por linea de comandos para convertirla en una CNF en el fichero de salida\n";
const std::string kUse = "Modo de empleo: ./dfa2grammar input.gra output.gra\n"
                        "Pruebe ’dfa2grammar --help’ para mas informacion.\n";
void Usage(int, char*[]);
