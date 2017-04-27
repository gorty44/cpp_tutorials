#include <iostream>
#include <string>

constexpr auto fx = [] (std::string msg) { 
	return msg + "!\n";
};

int main(int argc, char* argv[]) {
	
	if (argc == 2)
		std::cout << "hello " << fx(argv[1]);
	else 
		std::cout << "Hello world!" << std::endl;
}

