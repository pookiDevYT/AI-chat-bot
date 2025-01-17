#include "App.h"

void App::RunPy()
{

	std::system("python APIrequest.py");
}

void App::getRequest(){
	std::string line;
	std::ifstream output("output.txt");

	if (output.is_open()) while (std::getline(output, line))std::cout << line << '\n';
}

void App::writeToFile(const std::string fileName, const std::string& input){
	std::ofstream inputFile(fileName, std::ios::out);
	inputFile << input;
}

void App::formatOutput(std::string& input){
}

