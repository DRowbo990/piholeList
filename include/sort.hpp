#ifndef SORT_HPP
#define SORT_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int sizer(std::string s1, std::string s2);

int simpleCompare(int leftValue, int rightValue);

void alphabetize(std::ifstream &readFile, std::ofstream &output, std::string r, std::string w);

#endif
