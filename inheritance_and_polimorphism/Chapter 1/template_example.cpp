#include <iostream>
#include <typeinfo>

template<typename T>
struct MyStruct {
	T data;
};

template<typename U>
auto make_struct(U u) {
	return MyStruct<U>{ u };
}

int main() {
	auto myStruct = make_struct(15);
	std::cout << myStruct.data << std::endl;
	std::cout << (typeid(myStruct.data) == typeid(int)) << std::endl;
}	
