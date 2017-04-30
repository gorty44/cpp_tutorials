#include <iostream>

template<typename T>
struct MixIn {
	auto sum() {
		return static_cast<T*>(this)->lhs + static_cast<T*>(this)->rhs;
	}
};

struct Pair : MixIn<Pair> {
	int lhs = 0;
	int rhs = 0;
	using MixIn<Pair>::sum;
};

int main() {
	Pair p;
	p.lhs = 2;
	p.rhs = 3;
	std::cout << p.sum() << std::endl;
}
