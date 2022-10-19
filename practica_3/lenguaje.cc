#include "lenguaje.h"

Lenguaje::Lenguaje(std::string input) {
  int found = input.find("{");
  input.erase(ZERO, found + 1);
  std::string push;
  
  for (size_t i = 0; i < input.size(); i++) {
    if (input[i] != COMA && input[i] != SPACE && input[i] != '}') {
      push += input[i];
      alpha_.Build(input[i]);
    } else if (input[i] == SPACE || input[i] == '}'){ 
      if (!push.empty())
        cadenas_.insert(push);
      push.clear();
    }
  } 
}

Lenguaje operator+(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{"};
  bool detected_empty = false;

  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      if (str.GetCadena() != EMPTYSTR) {
        concatenated += str.GetCadena() + ", ";
      } else if (str2.GetCadena() != EMPTYSTR) {
        concatenated += str2.GetCadena() + ", ";
      } else {
        detected_empty = true;
      }
      
    }
  } 
  
  if (detected_empty) {
    concatenated += "&";
  }

  if (concatenated.size() >= 2) {
    concatenated.pop_back();
    concatenated.pop_back();
  }

  concatenated += "}";
  
  std::string total = concatenated; 
  Lenguaje result(total);

  return result;
}

Lenguaje operator|(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{"};
  bool detected_empty = false;
  bool detected_empty_2 = false;

  for (auto& str : in1.cadenas_) {
    if (str.GetCadena() != EMPTYSTR) {
      concatenated += str.GetCadena() + ", ";
    } else { 
      detected_empty = true;
    }
  } 
  for (auto& str2 : in2.cadenas_) {
    if (str2.GetCadena() != EMPTYSTR) {
      concatenated += str2.GetCadena() + ", ";
    } else {
      detected_empty_2 = true;
    }
  }

  if (detected_empty && detected_empty_2) {
    concatenated += "&";
  }

  if (concatenated.size() >= 2) {
    concatenated.pop_back();
    concatenated.pop_back();
  }

  concatenated += "}";
  
  std::string total = concatenated; 
  Lenguaje result(total);

  return result;
}

Lenguaje operator^(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{"};
  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      if (str.GetCadena() == str2.GetCadena()) {
        concatenated += str.GetCadena() + ", ";
      }
    }
  } 
  
  if (concatenated.size() >= 2) {
    concatenated.pop_back();
    concatenated.pop_back();
  }

  concatenated += "}";
  
  std::string total = concatenated; 
  Lenguaje result(total);

  return result;
}

Lenguaje operator-(const Lenguaje& in1, const Lenguaje& in2) {
  std::string concatenated = {"{"};
  for (auto& str : in1.cadenas_) {
    for (auto& str2 : in2.cadenas_) {
      if (str.GetCadena() != str2.GetCadena()) {
        concatenated += str.GetCadena() + ", ";
      }
    }
  } 
  if (concatenated.size() >= 2) {
    concatenated.pop_back();
    concatenated.pop_back();
  }
  concatenated += "}";
  
  std::string total = concatenated; 
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
    return (base + PowLenguage(base, n-1)); 
  }
}

void Lenguaje::SetLenguage(void) {
  std::string in = "&";
  cadenas_.clear();
  cadenas_.insert(in);
}

std::ostream& operator<<(std::ostream& out, const Lenguaje& in) {
  out << "{" << in.alpha_.GetAlpha() << "} " << "{" << in.GetCadenas() << "}";

  return out;
}

std::string Lenguaje::GetCadenas(void) const  {
  std::string result;
  for (auto& str : cadenas_) {
    result += str.GetCadena() + " ";
  }
  if (result.size() >= 2) {
    result.pop_back();
  }

  return result;
}
