#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

#include "lenguaje.h"

bool IsNumber(const std::string&);
void CalculatorRPN(std::string, std::map<std::string, Lenguaje>);
