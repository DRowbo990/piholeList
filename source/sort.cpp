
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

#include "../include/sort.hpp"

void insert(std::string s1, std::ifstream &readFile)
{

}

void alphabetize(std::ifstream &readFile, std::ofstream &output, std::string r, std::string w)
{
    int counter = 0;
    std::string s1;
    std::string s2;
    getline(readFile, s1);
    while (!readFile.eof())
    {
        ++counter;
        getline(readFile, s2);
        std::cout << s2 << std::endl;

        if((s1.compare(s2)) < 0)
        {
          output << s1 << std::endl;
        }
    
        else if((s1.compare(s2)) == 0)
        {
            std::cout << s1 << " is equal to " << s1 << std::endl;
        }
        else
        {
            output << s2 << std::endl;
        }

        if (counter % 10000 == 0)
        {
            std::cout << counter << " lines completed" << std::endl;
        }
    }

    std::cout << "Completed, " << counter << " total lines" << std::endl;
}

