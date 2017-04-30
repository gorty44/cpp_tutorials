// create a mixin that utilizes the < operator
// to provide ==, >, >=, !=, <= operators

#include <iostream>


template<typename T>
struct MixIn {
	bool operator<(const T& rhs) {
		return static_cast<T*>(this)->value < static_cast<T>(rhs).value;
	}
	bool operator==(const T& rhs) {
		return static_cast<T*>(this)->value == static_cast<T>(rhs).value;
	}
	bool operator>(const T& rhs) {
		return static_cast<T*>(this)->value > static_cast<T>(rhs).value;
	}
	bool operator>=(const T& rhs) {
		return static_cast<T*>(this)->value >= static_cast<T>(rhs).value;
	}
	bool operator!=(const T& rhs) {
		return static_cast<T*>(this)->value != static_cast<T>(rhs).value;
	}
	bool operator<=(const T& rhs) {
		return static_cast<T*>(this)->value <= static_cast<T>(rhs).value;
	}
};

struct Int : MixIn<Int>
{
	Int(const int t_value) : value(t_value) { }
	int value;
	using MixIn<Int>::operator<;
	using MixIn<Int>::operator==;
	using MixIn<Int>::operator>;
	using MixIn<Int>::operator>=;
	using MixIn<Int>::operator!=;
	using MixIn<Int>::operator<=;
};

int main() {
	Int i(5);
	Int j(6);

	bool result = i > j;
	std::cout << result << std::endl;

}
