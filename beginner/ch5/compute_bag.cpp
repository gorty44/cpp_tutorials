#include <iostream>
#include "compute_invoice.hpp"

int main() {
	double bag[] = { 2.0,3.0,4.0 };
	std::cout << compute_invoice(bag,3) << std::endl;
}
