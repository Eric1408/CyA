/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file usage.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "lenguaje.h"


const std::string kExplain  {"El modo de uso de este programa es el siguiente:\n"
                          "./lenguajesP02 <entrada.txt> <entrada_2.txt> <salida.txt> <opcode>\n"
                          "Este programa realiza una serie de operaciones sobre dos lenguajes dados con el opcode proporcionado, son las siguientes:\n"
                          "   1 -> Concatenacion de lenguajes\n"
                          "   2 -> Union de lenguajes\n"
                          "   3 -> Interseccion de lenguajes\n"
                          "   4 -> Diferencia de lenguajes\n"
                          "   5 -> Inversa de lenguajes\n"
                          "   6 -> Potencia de lenguajes\n"
                          "Donde una vez dado la informacion se guardara en <salida.txt>\n"};
const std::string kHelp {"./lenguajesP02: faltan o se ha pasado del numero de argumentos.\n"
                          "Pruebe './lenguajesP02 --help' para mas informacion\n"};
void Usage(int, char*[]);
void Selector(std::ofstream&, Lenguaje&, Lenguaje&, int);
