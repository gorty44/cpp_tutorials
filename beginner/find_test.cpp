#include <iostream>
#include <algorithm>
#include <vector>


int main() {
	std::vector<std::string> vec = {"raz", "dwa", "trzy"};
	auto iter = std::find(std::begin(vec), std::end(vec), "raz");

	if (iter != vec.end())
		std::cout << "Found" << std::endl;

	std::vector<int> a = {1,2,3,4,5};
	std::vector<int> b(0);
	std::copy(a.begin(), a.end(), b.begin());

//	auto fx = [&] (int rhs, int lhs) { return rhs*lhs; };

	for (int i : a)
		std::cout << i << std::endl;
}
