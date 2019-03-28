#include "SplitString.hpp"


std::vector<std::string> splitString(std::string text, char delimiter){
  /*
  Prend en parametre une chaine de caractere et la divise en plusieurs morceaux
  de textes en se servant du delimiteur.
  Renvoie un vecteur contenant les morceaux de textes.
  */
  if (text == "")
    return std::vector<std::string>();

  std::vector<std::string> res;
  unsigned int start_pos = 0;
  unsigned int it = 0;

  while (start_pos + it < text.length()){
    if (text[start_pos + it] == delimiter){
      // Ajoute le mot des que le delimiteur est rencontre
      res.push_back(text.substr(start_pos, it));
      start_pos += (it + 1);
      it = 0;
    }
    ++it;
  }
  // Ajoute le dernier mot
  res.push_back(text.substr(start_pos, text.length() - start_pos));

  return res;
}

std::string strVectorToStr(std::vector<std::string> vector){
  std::string res;

  for (unsigned int a = 0; a < vector.size(); ++a){
    if (a == vector.size()-1){
      res += vector[a];
    }
    else {
      res += (vector[a] + " ");
    }
  }

  return res;
}


std::vector<unsigned int> toUIVector(std::vector<std::string> vector){
  std::vector<unsigned int> res;

  for (unsigned int a = 0; a < vector.size(); ++a){
    res.push_back(std::stoi(vector[a]));
  }
  return res;
}

std::string unsignedIntVectorToStr(std::vector<unsigned int> vector){
  std::string res;

  for (unsigned int a = 0; a < vector.size(); ++a){
    if (a == vector.size()-1){
      res += std::to_string(vector[a]);
    }
    else {
      res += (std::to_string(vector[a]) + " ");
    }
  }
  return res;
}

std::vector<double> toDoubleVector(std::vector<std::string> vector){
  std::vector<double> res;

  for (unsigned int a = 0; a < vector.size(); ++a){
    res.push_back(std::atof(vector[a].c_str()));
  }
  return res;
}

std::string doubleVectorToStr(std::vector<double> vector){
  std::string res;
  std::stringstream stream;

  for (unsigned int a = 0; a < vector.size(); ++a){
    stream << std::fixed << std::setprecision(2) << vector[a];

    if (a == vector.size()-1){
      res += stream.str();
    }
    else {
      res += (stream.str() + " ");
    }
    stream.str("");
  }
  return res;
}
