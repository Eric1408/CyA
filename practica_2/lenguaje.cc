#include "lenguaje.h"

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

Lenguaje Lenguaje::PowLenguage(const Lenguaje& base, int n) {
  Lenguaje zero = base;
  if (n == -1) {
    zero.SetLenguage();
    return zero;
  }
  if (n == 0) {
    return zero;
  } else {
    return (base * PowLenguage(base, n-1)); 
  }
}

void Lenguaje::SetLenguage(void) {
  std::string in = "&";
  cadenas_.clear();
  cadenas_.insert(in);
}

std::ostream& operator<<(std::ostream& out, const Lenguaje& in) {
  out << "{ " << in.alpha_.GetAlpha() << "}" << " { " << in.GetCadenas() << "}";

  return out;
}

std::string Lenguaje::GetCadenas(void) const  {
  std::string result;
  for (auto& str : cadenas_) {
    result += str.GetCadena() + " ";
  }

  return result;
}
