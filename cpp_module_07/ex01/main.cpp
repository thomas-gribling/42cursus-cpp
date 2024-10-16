#include "Iter.hpp"

void square(int &n) {
	n *= n;
}

int main() {
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int len = 10;

	std::cout << std::endl << "BEFORE: ";
	for (int i = 0; i < len - 1; i++) {
		std::cout << array[i] << ", ";
	}
	std::cout << array[len - 1] << std::endl;

	iter(array, len, square);

	std::cout << "AFTER:  ";
	for (int i = 0; i < len - 1; i++) {
		std::cout << array[i] << ", ";
	}
	std::cout << array[len - 1] << std::endl << std::endl;
	return 0;
}