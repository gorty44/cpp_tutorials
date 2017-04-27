/*
 *
 *	calc <num 1> op <num 2>
 *		returns the operation on the two numbers
 *
 *
*/

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "You should pass 3 arguments" << std::endl;
		return 1;
	}	
	
	double lhs = std::stod(argv[1]);
	double rhs = std::stod(argv[3]);
	std::string op = argv[2];	
	
	if (op == "+") {
		std::cout << lhs + rhs << std::endl;
	} else if (op == "-") {
		std::cout << lhs - rhs << std::endl;
	} else if (op == "x") {
		std::cout << lhs * rhs << std::endl;
	} else if (op == "/") {
		if (rhs != 0) 
			std::cout << lhs / rhs << std::endl;
		else
			std::cout << "Can't divide by 0" << std::endl;
	} else {
		std::cerr << "Error: op " << op << " not supported" << std::endl;
		return 1;
	}
}

