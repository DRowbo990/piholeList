
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

#include "../include/sort.hpp"
#include "../include/tests.hpp"


// definitions for main.cpp local functions
//int runProgram(void);

int main(int argc, char* argv[])
{
    //set up file names and check file validity.
    std::ifstream readFile;
    std::ofstream output;
    std::string r = argv[1];
    std::string w = argv[2];

	readFile.open(argv[1]);
    output.open(argv[2]);

	if (!readFile.good())
	{
		std::cout << "File doesn't exist. Closing program" << std::endl;
		exit(1);
	}

    alphabetize(readFile, output, r, w);
}
