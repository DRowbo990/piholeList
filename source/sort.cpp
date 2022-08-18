#include <fstream>
#include <iostream>
#include <string>
#include "../include/sort.hpp"

bool alphabetize(std::ifstream& test, std::ofstream& output)
{
    std::string line;
    while(!test.eof())
    {
        getline(test, line);
        output << line << std::endl;
    }
    //int compare (const string& string-name) const;
    return true;
}

int simpleCompare(int leftValue, int rightValue)
{
    // to be implemented
    return 0;
}
