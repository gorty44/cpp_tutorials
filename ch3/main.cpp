#include <iostream>

constexpr double pi = 3.14159;

int calc_circum(int radius) {
	return 2*pi*radius;
};

int main(int argc, char* argv[]) {

	int i;
	std::cout << "uninitialized i = " << i << std::endl;
	const double circum = calc_circum(15);
	std::cout << "circum = " << circum << std::endl;

}
