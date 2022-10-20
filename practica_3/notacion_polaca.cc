#include "notacion_polaca.h"

/**
 * @brief Funcion que detecta si es un numero pasado un string
*/
bool IsNumber(const std::string& input) {
  for (char const &chr : input) {
    if (std::isdigit(chr) == 0) {
      return false;
    }
  }

  return true;
}

/**
 * @brief Funcion que desarolla operaciones en notacion posfija mediante el uso de la pila
 * @param string 
 * @param map<string, Lenguaje>
*/
void CalculatorRPN(std::string input, std::map<std::string, Lenguaje> lenguajes_map) {
  std::stack<int> n;
  std::stack<Lenguaje> lenguaje_stack;


  std::vector<std::string> entrada;
  Lenguaje op1, op2;
  std::string push;
  input.push_back(' ');

  for (size_t i = 0; i < input.size(); ++i) {
    if (!isspace(input[i])) {
      push += input[i];
    } else {
      entrada.push_back(push);
      push.clear();
    }
  }

  size_t i = 0;
  while (i < entrada.size()) {
    if (entrada[i] != "+" && entrada[i] != "|" && entrada[i] != "^" && entrada[i] != "-" && entrada[i] != "!" && entrada[i] != "*") {
      if (IsNumber(entrada[i])) {
        n.push(stoi(entrada[i]) - 1);
      } else {
        lenguaje_stack.push(lenguajes_map[entrada[i]]);
      }

    } else {
      if (entrada[i] == "!" || entrada[i] == "*") {
        if (lenguaje_stack.size() < 1) {
          std::cout << "ERROR: operandos insuficientes en la operacion ! o *\n";
        } else {
          op1 = lenguaje_stack.top();
          lenguaje_stack.pop();
          if (entrada[i] == "!") {
            op1.ReverseLenguage();
            lenguaje_stack.push(op1);
          } else if (entrada[i] == "*") {
            lenguaje_stack.push(op1.PowLenguage(op1, n.top()));
            n.pop();
          }
        }
      } else {
        if (lenguaje_stack.size() < 2) {
          std::cout << "ERROR: operandos insuficientes en la operacion\n";
        } else {
          op1 = lenguaje_stack.top();
          lenguaje_stack.pop();
          op2 = lenguaje_stack.top();
          lenguaje_stack.pop();
          
          if (entrada[i] == "+") {
            lenguaje_stack.push(op1 + op2);
          } else if (entrada[i] == "|") {
            lenguaje_stack.push(op1 | op2);
          } else if (entrada[i] == "^") {
            lenguaje_stack.push(op1 ^ op2);
          } else if (entrada[i] == "-") {
            lenguaje_stack.push(op1 - op2);
          }
        }
      }
    }
    ++i;
  }

  if (lenguaje_stack.size() == 1) {
    std::cout << lenguaje_stack.top();
  } else {
    std::cout << "ERROR\n";
  }
  std::cout << std::endl;
}
