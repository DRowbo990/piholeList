
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

#include "../include/sort.hpp"

// void erase(std::string r)
// {
//     std::ofstream writeFile;
//     writeFile.open(r.c_str());

//     while (getline(fin,line))
//     {
//         line.replace(line.find(deleteline),deleteline.length(),"");
//         temp << line << endl;

//     }
// }

int compare(std::string s1, std::string s2, std::string r, std::string w)
{
    std::ifstream readFile;
    std::ofstream writeFile;

    readFile.open(r.c_str());
    getline(readFile, s1);
    while (!readFile.eof())
    {
        while(readFile.peek() != EOF )
        {
            getline(readFile, s2);
            if((s1.compare(s2)) < 0)
            {

            }
            else if((s1.compare(s2)) == 0)
            {
                break;
            }
            else
            {
                s1 = s2;
            }
        }

    }
    writeFile.open(w.c_str());
    writeFile << s1 << std::endl;
    //eraseFileLine(r, s1);
    readFile.close();
    writeFile.close();
    return 0;

}

void insert(std::string s1, std::ifstream &readFile)
{

}

void alphabetize(std::ifstream &readFile, std::ofstream &output, std::string r, std::string w)
{
    int counter = 0;
    std::string s1;
    std::string s2;
    while (!readFile.eof())
    {
        getline(readFile, s1);
        getline(readFile, s2);
        std::cout << s1 << std::endl;
        std::cout << s1 << std::endl;
        compare(s1, s2, r, w);
    }

    std::cout << "Completed, " << counter << " total lines" << std::endl;
}

