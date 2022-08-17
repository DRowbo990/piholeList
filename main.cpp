
#include <iostream>
#include "sort.h"
#include "tests.h"

// definitions for main.cpp local functions
int runProgram(void);

int main()
{
    int result = 0;
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
    return 0;
}
