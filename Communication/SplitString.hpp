#ifndef _SPLITSTRING_H_
#define _SPLITSTRING_H_

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

std::vector<std::string> splitString(std::string, char);
std::string strVectorToStr(std::vector<std::string>);

std::vector<unsigned int> toUIVector(std::vector<std::string>);
std::string unsignedIntVectorToStr(std::vector<unsigned int>);

std::vector<double> toDoubleVector(std::vector<std::string>);
std::string doubleVectorToStr(std::vector<double>);

#endif
