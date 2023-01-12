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

const std::string kHelp{"Numero de parametros incorrectos.\nPruebe ./multbigint '--help' para mas informacion.\n"};
const std::string kExplain{"Este programa multiplica enteros positivos grandes.\nAcepta las siguiente opciones:\n  -k --> Para utilizar el algoritmo recursivo de Karatsuba\n"
                            " -m --> utiliza la multiplicacion del operador sobrecargado '*' de la clase BigInt\n"
                            " -n <cota> --> donde dada una cota utilizara el algoritmo de karatsuba o la sobrecarga"};
void Usage(int, char*[]);