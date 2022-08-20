
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
    std::ifstream readFile;
    std::ofstream output;
	readFile.open(argv[1]);
    output.open(argv[2]);
	if (!readFile.good())
	{
		std::cout << "File doesn't exist. Closing program" << std::endl;
		exit(1);
	}

    alphabetize(readFile, output);
    
    /*int result = 0;
    // run tests before starting program
    result = runTests();
    if (result != 0)
    {
        // testing failed
        std::cout << "Testing failed." << std::endl;
        std::cout << "Result code: " << result << std::endl;
    }
    else
    {
        // testing succeeded
        std::cout << "Testing succeeded." << std::endl;
        // run program
        result = runProgram();
        if (result != 0)
        {
            // program failed
            std::cout << "Program failed." << std::endl;
            std::cout << "Result code: " << result << std::endl;
        }
        else
        {
            // program succeeded
            std::cout << "Program succeeded." << std::endl;
        }
    }
    return result;
}
int runProgram()
{
    // run the actual program to sort the file
    return 0;*/
}
