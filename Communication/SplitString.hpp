#include <string>
#include <vector>

#ifndef _SPLITSTRING_H_
#define _SPLITSTRING_H_

std::vector<std::string> splitString(std::string, char);

std::vector<unsigned int> toUIVector(std::vector<std::string>);

std::string unsignedIntVectorToStr(std::vector<unsigned int>);

std::string strVectorToStr(std::vector<std::string>);

#endif
