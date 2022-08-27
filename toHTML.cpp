/*******************************************************************************
Function: takes a .txt file and puts it into html format. Only for pihole block
	lists

Input: command line arguments
Outputs: file

Compile instructions: g++ Source.cpp -o Source.exe
********************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream readFile;
	std::ofstream output;
	std::string name;
	int counter = 0;

	readFile.open(argv[1]);
	output.open(argv[2]);

	if (!readFile.good())
	{
		std::cout << "File doesn't exist. Closing program" << std::endl;
		exit(1);
	}

	output << "<!DOCTYPE html>\n" << "<html>\n" << "<body>\n";
	output << "<pre style=\"word-wrap: break-word; white-space; pre-wrap;\">\n";
	
	while (!readFile.eof())
	{
		++counter;
		getline(readFile, name);
		output << name << " ";
		output << "<br>";

		if (counter % 10000 == 0)
		{
			std::cout << counter << " lines completed" << std::endl;
		}
	}
	std::cout << "Completed, " << counter << " total lines" << std::endl;
	output << "<" << '/' << "pre>\n";
	output << "<" << '/' << "body>\n";
	output << "<" << '/' << "html>\n";
}