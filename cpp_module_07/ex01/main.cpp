#include "Iter.hpp"

void square(int &n) {
	n *= n;
}

void display(double const &d) {
	std::cout << d << std::endl;
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
	std::cout << array[len - 1] << std::endl;


	double darray[] = {0.1, 1.5, 3.4, 6.6};
	len = 4;

	std::cout << std::endl << "DISPLAY TEST:" << std::endl;
	iter(darray, len, display);
	std::cout << std::endl;
	return 0;
}