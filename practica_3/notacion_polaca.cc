#include "notacion_polaca.h"

void CalculatorRPN(std::string input, std::map<std::string, Lenguaje> lenguajes_map) {
  std::stack<std::string> operar;
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

  int i = 0;
  while (i < entrada.size()) {
    if (entrada[i] != "+" && entrada[i] != "|" && entrada[i] != "^" && entrada[i] != "-" && entrada[i] != "!" && entrada[i] != "*") {
      lenguaje_stack.push(lenguajes_map[entrada[i]]);
    } else {
      if (entrada[i] == "!" && entrada[i] == "*") {
        if (lenguaje_stack.size() < 1) {
          std::cout << "ERROR: operandos insuficientes en la operacion\n";
        } else {
          op1 = lenguaje_stack.top();
          lenguaje_stack.pop();
          if (entrada[i] == "!") {
            op1.ReverseLenguage();
            lenguaje_stack.push(op1);
          } else {
            //aqui va la potencia
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
