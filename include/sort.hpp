#ifndef SORT_HPP
#define SORT_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void eraseFileLine(std::string path, std::string eraseLine); 

int sizer(std::string s1, std::string s2);

//int simpleCompare(int leftValue, int rightValue);

int compare(std::string s1, std::string s2, std::string r, std::string w);


void alphabetize(std::ifstream &readFile, std::ofstream &output, std::string r, std::string w);

#endif
