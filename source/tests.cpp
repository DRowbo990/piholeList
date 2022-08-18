#include <iostream>
#include "tests.hpp"
#include "sort.hpp"

// definitions for tests.cpp local functions
bool testSimpleCompare1();
bool testSimpleCompare2();
bool testSimpleCompare3();

// run tests. Return value 0 if tests pass. Otherwise return value = test number
int runTests()
{
    if (!testSimpleCompare1())
        return 1;
    if (!testSimpleCompare2())
        return 2;
    if (!testSimpleCompare3())
        return 3;

    return 0;
}
bool testSimpleCompare1()
{
    // simpleCompare() should return 0 if both values are the same
    int result = simpleCompare(0, 0);
    if (result == 0)
        return true;

    std::cout << "simpleCompare(0, 0) should have returned 0." << std::endl;
    std::cout << "Actual Value: " << result << std::endl;
    return false;
}
bool testSimpleCompare2()
{
    // simpleCompare() should return a value less than 0 if the left value is less
    int result = simpleCompare(0, 1);
    if (result < 0)
        return true;

    std::cout << "simpleCompare(0, 1) should have returned a value less than 0." << std::endl;
    std::cout << "Actual Value: " << result << std::endl;
    return false;
}
bool testSimpleCompare3()
{
    // simpleCompare() should return a value greater than 0 if the left value is more
    int result = simpleCompare(1, 0);
    if (result > 0)
        return true;

    std::cout << "simpleCompare(1, 0) should have returned a value greater than 0." << std::endl;
    std::cout << "Actual Value: " << result << std::endl;

    return false;
}
