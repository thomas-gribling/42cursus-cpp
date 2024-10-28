#include "Array.hpp"

int main() {
	std::cout << std::endl << "=== INT ARRAY, SIZE 0 ===" << std::endl;
	try {
		Array<int> a;

		std::cout << a.size() << std::endl;
		std::cout << a[0] << std::endl;
		std::cout << a[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "=== DOUBLE ARRAY, SIZE 1 ===" << std::endl;
	try {
		Array<double> a(1);
		
		std::cout << a.size() << std::endl;
		a[0] = 1.5;
		std::cout << a[0] << std::endl;
		std::cout << a[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== STRING ARRAY, SIZE 42 ===" << std::endl;
	try {
		Array<std::string> a(42);
		
		std::cout << a.size() << std::endl;
		a[31] = "test";
		std::cout << a[12] << std::endl;
		std::cout << a[31] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== NEGATIVE INDEX ===" << std::endl;
	try {
		Array<int> a(3);

		std::cout << a.size() << std::endl;
		std::cout << a[-1] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}