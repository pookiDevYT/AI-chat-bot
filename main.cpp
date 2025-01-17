#include "App.h"

int main() {
	App app;
	std::string input;
	while (true) {
		std::cout << "you: ";
		std::getline(std::cin, input);
		if (input == "exit"){
			std::cout << "chat endend\n";
			break;
		}
			//AI part
		app.writeToFile("input.txt", input);
		app.RunPy();
		app.getRequest();
	}
	return 0;
}