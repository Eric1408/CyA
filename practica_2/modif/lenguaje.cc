#include "lenguaje.h"

/**
 * @brief constructor de la clase lenguaje que recibe toda una linea y la separa en alfabeto y set de cadenas
 * 
*/
Lenguaje::Lenguaje(std::string input) {
  int counter = 0;
  for (size_t i = 0; i < input.size(); ++i) {
    counter++;
    if (input[i] == '}') {
      break;
    }

    if (input[i] != '{' && input[i] != SPACE) {
      alpha_.Build(input[i]);
    } 
  }
  input.erase(ZERO, counter + 1);
  std::string push;
  for (size_t i = 2; i < input.size() - 1; ++i) {
    if (input[i] != SPACE) {
      push += input[i];   
    } else {
      cadenas_.insert(push);
      push = "";
    }
  }
}

/**
 * @brief Sobrecarga del operador * como concatenacion
*/
Lenguaje operator*(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{ "};
  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      concatenated += str.GetCadena() + str2.GetCadena() + " ";
    }
  } 
  concatenated += "}";
  
  std::string alphabet{"{ "};
  for (auto& str : in1.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  for (auto& str : in2.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  alphabet += {"} "};
  std::string total = alphabet + concatenated; 
  Lenguaje result(total);

  return result;
}

/**
 * @brief Sobrecarga del operador + como union
 * 
*/
Lenguaje operator+(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{ "};
  for (auto& str : in1.cadenas_) {
    concatenated += str.GetCadena() + " ";
  } 
  for (auto& str2 : in2.cadenas_) {
    concatenated += str2.GetCadena() + " ";
  }
  concatenated += "}";
  
  std::string alphabet{"{ "};
  for (auto& str : in1.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  for (auto& str : in2.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  alphabet += {"} "};
  std::string total = alphabet + concatenated; 
  Lenguaje result(total);

  return result;
}

/**
 * @brief Sobrecarga del operador / como interseccion
 * 
*/
Lenguaje operator/(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{ "};
  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      if (str.GetCadena() == str2.GetCadena()) {
        concatenated += str.GetCadena() + " ";
      }
    }
  } 
  
  concatenated += "}";
  
  std::string alphabet{"{ "};
  for (auto& str : in1.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  for (auto& str : in2.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  alphabet += {"} "};
  std::string total = alphabet + concatenated; 
  Lenguaje result(total);

  return result;
}

/**
 * @brief Sobrecarga del operador - como diferencia
 * 
*/
Lenguaje operator-(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{ "};
  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      if (str.GetCadena() != str2.GetCadena()) {
        concatenated += str.GetCadena() + " ";
      }
    }
  } 

  concatenated += "}";
  
  std::string alphabet{"{ "};
  for (auto& str : in1.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  for (auto& str : in2.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  alphabet += {"} "};
  std::string total = alphabet + concatenated; 
  Lenguaje result(total);

  return result;
}

/**
 * @brief Funcion que hace el reverse de las cadenas de un lenguaje
 * 
*/
void Lenguaje::ReverseLenguage(void) {
  std::vector<std::string> aux;
  for (auto& str : cadenas_) {
    aux.push_back(str.Reverse());
  }
  cadenas_.clear();  
  for (size_t i = 0; i < aux.size(); ++i) {
    cadenas_.insert(aux[i]);
  }

}

/**
 * @brief Metodo que hace la poencia de un lenguaje de forma recursiva
*/
Lenguaje Lenguaje::PowLenguage(const Lenguaje& base, int expo) {
  Lenguaje zero = base;
  if (expo == -1) {
    zero.SetEmptyStr();
    return zero;
  }
  if (expo == 0) {
    return zero;
  } else {
    return (base * PowLenguage(base, expo-1)); 
  }
}

/**
 * @brief Coloca el lenguaje a cadena vacia '&'
 * 
*/
void Lenguaje::SetEmptyStr(void) {
  std::string in = "&";
  cadenas_.clear();
  cadenas_.insert(in);
}

/**
 * @brief Sobrecarga del operador <<
 * 
*/
std::ostream& operator<<(std::ostream& out, const Lenguaje& in) {
  out << "{ " << in.alpha_.GetAlpha() << "}" << " { " << in.GetCadenas() << "}";

  return out;
}

/**
 * @brief Metodo que devuelve las cadenas de un Lenguaje en un string
 * @return std::string
*/
std::string Lenguaje::GetCadenas(void) const  {
  std::string result;
  for (auto& str : cadenas_) {
    result += str.GetCadena() + " ";
  }

  return result;
}

Lenguaje operator*(const Lenguaje& input, std::string str_input) {
  std::string concatenated = {"{ "};
  for (auto& str : input.cadenas_) {
    concatenated += str.GetCadena() + str_input + " ";
  } 
  concatenated += "}";
  
  std::string alphabet{"{ "};
  for (auto& str : input.alpha_.GetSetAlpha()) {
    alphabet.push_back(str.GetSymbol());
    alphabet +={" "};
  }
  for (size_t i = 0; i < str_input.size(); ++i) {
    alphabet.push_back(str_input[i]);
    alphabet.push_back(SPACE);
  }
  alphabet += {"} "};
  std::string total = alphabet + concatenated; 
  Lenguaje result(total);

  return result;
}
