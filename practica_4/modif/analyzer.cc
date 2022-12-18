#include "analyzer.h"

/**
 * @name Build
 * @brief Metodo que permite construir la clase Analyzer
*/
void Analyzer::Build(std::string input, int pos) {
  std::regex expression_var("[^[:graph:]](int|double)\\s(\\w+(\\s*=\\s*\\w+)?)");
  std::regex expression_loop("\\s*[^\\w](for|while)");
  std::regex expression_main("int main");
  //std::regex expression_comments("^\\s*(\\/\\/.*)");
  std::regex expression_comments("^\\s*(\\/\\/.*)|^\\s*[^:]\\s*(\\/\\/.*)");
  //std::regex expression_comments("^\\s*(\\/\\/.*)|^\\s*(\\/\\*)|^\\s*.*|^\\s*(\\*\\/)");
  std::regex expression_description("(\\/\\*\\*)|(^\\s\\*.*)");
  //std::regex descript_ini("^\\/\\*\\*");
  std::regex descript_ini("^\\s*\\/\\*\\*?");
  std::regex descript_end("\\s\\*\\/");
  //std::regex expression_comments(".*[^:](\\/\\/.*)");

  std::smatch matches;
  std::smatch aux;
  
  
  if (std::regex_search(input, matches, expression_var)) {
    variables_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_loop)) {
    loops_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_main)) {
    main_ = true;
  } else if (std::regex_search(input, matches, expression_comments)) {
    comments_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_description)) {
    if (std::regex_search(input, aux, descript_ini)) {
      descript_.Build(aux, pos);
    } else if (std::regex_search(input, aux, descript_end)) {
      descript_.Insert(aux, pos);
    } else {
      descript_.Insert(matches);
    }
  }
}

/**
 * @name 
 * @brief Sobrecarga del operador <<
*/
std::ostream& operator<<(std::ostream& out, const Analyzer& kAnaly) {
  out << "DESCRIPTION :\n" << kAnaly.descript_ << std::endl;
  
  out << "\nVARIABLES :\n";
  for (int i = 0; i < kAnaly.VarSize(); i++) {
    out << kAnaly.variables_[i] << std::endl;
  }
  
  out << "\nSTATEMENTS :\n";
  for (int i = 0; i < kAnaly.LoopSize(); ++i) {
    out << kAnaly.loops_[i] << std::endl;
  }
  
  out << "\nMAIN :\n";
  kAnaly.main_ ? out << "True\n" : out << "False\n";

  out << "\nCOMMENTS :\n";
  out << "[LINE " << kAnaly.descript_.GetInit() << "-" << kAnaly.descript_.GetEnd() << "] DESCRIPTION\n"; 
  for (int i = 0; i < kAnaly.CommentSize(); ++i) {
    out << kAnaly.comments_[i] << std::endl;   
  }
  
  return out;
}

void Analyzer::DeleteFor(std::string lines) {
  std::regex expression_loop("\\s*[^\\w](for).*");
  std::smatch matches;

  if (!std::regex_search(lines, matches, expression_loop)) {
    new_code_.push_back(lines + "\n");
  }
}

bool Analyzer::ForIni(std::string input) {
  std::regex expression_loop("\\s*[^\\w](for).*");
  std::smatch matches;

  if (std::regex_search(input, matches, expression_loop)) {
    for_ini_ = true;
    return true;
  } 
  
  return false;
}

bool Analyzer::ForFin(std::string input) {
  std::regex expression_loop("^\\s\\}$");
  std::smatch matches;

  if (std::regex_search(input, matches, expression_loop)) {
    return true;
    for_ini_ = true;
  } 
  for_ini_ = false;
  return false;
}
