#include <iostream>

int main(int argc, char* argv[]) {
	int* array = new int[3];
	array[0] = 15;
	array[1] = 5;
	array[2] = 3;

	for (int i = 0; i < 3; i++) {
		std::cout << array[i] << std::endl;
		delete *array[i];
	}
	delete [] array;
}
