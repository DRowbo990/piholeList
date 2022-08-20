#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "../include/sort.hpp"

void compareOperation(std::string s1, std::ifstream &readFile)
{
    std::string s2;

    while(!readFile.eof())
    {
        getline(readFile, s2);
        // returns a value < 0 (s1 is smaller than s2)
        if((s1.compare(s2)) < 0)
        {
            std::cout << s1 << " is smaller than " << s2 << std::endl;
        }
    
        // returns 0(s1, is being compared to itself)
        else if((s1.compare(s1)) == 0)
        {
            std::cout << s1 << " is equal to " << s1 << std::endl;
        }
        else
        {
            std::cout << "Strings didn't match ";
        }
    }
     
}

bool alphabetize(std::ifstream &readFile, std::ofstream &output)
{
    int counter = 0;
    std::string line;
    while (!readFile.eof())
    {
        ++counter;
        getline(readFile, line);
        compareOperation(line, readFile);

        output << line << std::endl;
        if (counter % 10000 == 0)
        {
            std::cout << counter << " lines completed" << std::endl;
        }
    }

    std::cout << "Completed, " << counter << " total lines" << std::endl;
    return true;
}

int simpleCompare(int leftValue, int rightValue)
{
    // to be implemented
    return 0;
}
