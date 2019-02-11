#ifndef _SPLITSTRING_H_
#define _SPLITSTRING_H_

#include <string>
#include <vector>

std::vector<std::string> splitString(std::string text, char delimiter){
  /*
  Prend en parametre une chaine de caractere et la divise en plusieurs morceaux
  de textes en se servant du delimiteur.
  Renvoie un vecteur contenant les morceaux de textes.
  */

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

#endif
