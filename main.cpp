
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

#include "sort.h"
#include "tests.h"


// definitions for main.cpp local functions
//int runProgram(void);

int main(int argc, char* argv[])
{
    std::ifstream test;
    std::ofstream output;
	test.open(argv[1]);
    output.open(argv[2]);
	if (!test.good())
	{
		std::cout << argv[1] << " File doesn't exist. Closing program" << std::endl;
		exit(1);
	}

    alphabetize(test, output);
    
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
