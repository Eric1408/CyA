#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

const char SPACE = ' ';
const char ENDL = '\n';
const int ZERO = 0;

class Simbolo {
 public:
  Simbolo(void) : symbol_("") {}
  Simbolo(std::string input) {symbol_ = input;}

  std::string GetSymbol(void) {return symbol_;}

  void Write(std::ostream&) const;

 private:
  std::string symbol_;
};

void Simbolo::Write(std::ostream& os) const {
  os << symbol_;
}

std::ostream& operator<<(std::ostream& os, const Simbolo& symbol) {
  symbol.Write(os);
  return os; 
}

class Alfabeto {
 public:
  Alfabeto(void) : symbol_{} {}
  Alfabeto(std::string);


  void GetAlpha(void);
  void Build(std::string);
  inline int Size(void) {return symbol_.size();}
  inline Simbolo at(int pos) {return symbol_[pos];}

 private:
  std::vector<Simbolo> symbol_;
  //std::set<Simbolo> set_symbol_;
};

void Alfabeto::GetAlpha(void) {
  
  ////////// GETALPHA PARA STD::SET 

  //for (auto& i: set_symbol_) {
  //  std::cout << i  << ' ';
  //  
  //}
  
  for (int i = 0; i < symbol_.size(); ++i) {
    std::cout << symbol_[i] << " ";
  }
}

void Alfabeto::Build(std::string input) {
  
  ////////// BUILD PARA STD::SET
  
  //int find_space = input.find(SPACE);
  //std::string push_string{""};
  
  //if (find_space != std::string::npos) {
  //  for (int i = 0; i < input.size(); ++i) {
  //    if (input[i] != SPACE) {
  //      push_string += input[i];
  //    } else {
  //      set_symbol_.insert(push_string);
  //    }
  //  }
  //} else {
  //  for (int i = 0; i < input.size(); ++i) {
  //    push_string = input[i];
  //    set_symbol_.insert(push_string);
  //  }
  //} 
  
  ////////// CONSTRUCTOR QUE FUNCIONA CON VECTOR<SIMBOLO>
  
  bool space{true};
  int size = input.size();
  std::string push_string{""};
  
  size_t found = input.find(SPACE);
  if (found != std::string::npos) {
    for (int i = 0; i < size; ++i) {
      if (input[i] != SPACE) {
        push_string += input[i];
      } else if (input[i] == SPACE || ENDL){
        space = false;
        symbol_.push_back(push_string);
        push_string = "";
      }
    }
  } else {
    int counter;
    push_string = input[0];
    symbol_.push_back(push_string);
    for (int i = 0; i < size; ++i) {
      counter = 0;
      for (int j = 0; j < symbol_.size() ; ++j) {
        push_string = input[i];
        if (push_string != symbol_[j].GetSymbol()) {
          counter++;
          if (counter == symbol_.size()) {
            symbol_.push_back(push_string);
          }
        }
      }
    } 
  }
  // metodo sort para ordenar el alphabeto de mayor a menor
  std::sort(symbol_.begin(), symbol_.end());
}

class Cadena : public Alfabeto {
 public:
  Cadena(void) : length_{0} {}
  Cadena(std::string);

  inline int Length(void) {return length_;}
  void Reverse(void);
  void Prefix(void);
  void Suffix(void);
  void Substring(void);

 private:
  int length_;
  std::string cadena_;
  Alfabeto alpha_;
  std::vector<Simbolo> sim_cadena_;
};

void Cadena::Prefix(void) {
  std::cout << "& ";
  for (int i = 1; i <= length_; ++i) {
    std::cout << cadena_.substr(ZERO, i) << ' ';
  }
}

void Cadena::Suffix(void) {
  std::cout << "& ";
  int pos = 0;
  
  for (int i = 1; i <= length_; ++i) {
    pos = length_ - i;
    std::cout << cadena_.substr(pos, i) << ' ';
  }
}

void Cadena::Substring(void) {
  std::cout << "& ";
  for (int i = 0; i < alpha_.Size(); i++) {
    std::cout << alpha_.at(i) << " ";
  }
  

  for (int i = 1; i <= length_; i++) {
    for (int j = 0; j < length_; j++) {
      //std::cout << cadena_.substr(j, i) << " ";
    }
  }
  
}

void Cadena::Reverse() {
  for (int i = length_; i >= ZERO; --i) 
    std::cout <<  cadena_[i];
}

Cadena::Cadena(std::string input) {
  int last_space = input.find_last_of(SPACE);
  int size = input.size() - last_space;
  //std::cout << "last_space = " << last_space << " input.substr : " << input.substr(ZERO, last_space) << '\n';
  alpha_.Build(input.substr(ZERO, last_space));
  alpha_.GetAlpha();

  if (last_space != std::string::npos) {
    for (int i = 0; i < alpha_.Size(); ++i) {
      int ok_string = input.find(alpha_.at(i).GetSymbol());
      if (ok_string == std::string::npos) {
        std::cout << "La cadena no pertenece al alfabeto.\n";
      } else {
        
      }
    }  
    
    length_ = input.size() - last_space - 1;
    cadena_ = input.substr(last_space, length_);
  } else {
    length_ = input.size();
    cadena_ = input;
  }

////////// CONSTRUCTOR QUE FUNCIONA CON STRINGS Y COGE LA CADENA DESDE EL FINAL

  //const int size = input.size();
  //int i = size;
  //length_ = -1;
//
  //while (input[i] != SPACE) {
  //  length_++;
  //  length_ > size ? length_ = input.size() : length_ ;
  //  --i;
  //}
//
  //int cadena_begin = size - length_;
  //cadena_ = input.substr(cadena_begin, length_);
  //
  //int alpha_size = size - length_;
  //alpha_size == ZERO ? alpha_size = size : alpha_size;  
  //alpha_.Build(input.substr(ZERO, alpha_size));

}
