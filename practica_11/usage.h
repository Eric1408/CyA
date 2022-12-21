/**
 * @file usage.h
 * @author Eric Angueta Rogel 
 * @brief 
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

const std::string kHelp{"./monedas numero de argumentos incorrecto.\nPruebe './monedas --help' para mas informacion\n"};
const std::string kExplain{"El programa monedas da el cambio de cierta cantidad que haya introducido el usuario el modo de empleo es el siguiente:\n"
                           "  './monedas [-o][-b] [-b][-o] cantidad':\n   [-b] da la opcion de agregar billetes\n   [-o] utiliza algoritmo optimo O(m)\n"};
void Usage(int, char*[]);