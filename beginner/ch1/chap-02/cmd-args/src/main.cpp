#include <iostream>

int main(int argc, char* argv[]) {
	if (argc < 6) {
		std::cerr << "Invalid number of arguments - at least 5 required" << std::endl;
		return 1;
	}
	std::cout << "Total # of args: " << argc << std::endl;
	for (int i = 0; i < argc; i++) 
		std::cout << "Argument#" << i << ": " << argv[i] << std::endl;
}
