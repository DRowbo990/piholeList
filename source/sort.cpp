#include <fstream>
#include <iostream>
#include <string>
#include "../include/sort.hpp"

bool alphabetize(std::ifstream &test, std::ofstream &output)
{
    int counter = 0;
    std::string line;
    while (!test.eof())
    {
        ++counter;
        getline(test, line);
        output << line << std::endl;
        if (counter % 10000 == 0)
        {
            std::cout << counter << " lines completed" << std::endl;
        }
    }
    std::cout << "Completed, " << counter << " total lines" << std::endl;
    // int compare (const string& string-name) const;
    return true;
}

int simpleCompare(int leftValue, int rightValue)
{
    // to be implemented
    return 0;
}
