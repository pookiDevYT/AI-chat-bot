#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
class App
{
public:
	//declar vars
	std::string input;
	std::string output;
	std::vector<std::string> RememberData;

	//declar functions
	void RunPy();
	void writeToFile(const std::string fileName, const std::string& input);
	void getRequest();
	void formatOutput(std::string& input);
};

