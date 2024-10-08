#include "Bureaucrat.hpp"

int	main() {
	std::cout << std::endl << "=== CONSTRUCTOR TEST ===" << std::endl;
	try {
		Bureaucrat b("Micheal", 3);
		std::cout << b;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Micheal", 0);
		std::cout << b;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Micheal", 151);
		std::cout << b;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== INCREMENT TEST ===" << std::endl;
	try {
		Bureaucrat b("Jim", 3);
		std::cout << "[BEFORE] " << b;
		b.incrementGrade();
		std::cout << "[INCR 1] " << b;
		b.incrementGrade(3);
		std::cout << "[INCR 3] " << b;
		
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== DECREMENT TEST ===" << std::endl;
	try {
		Bureaucrat b("Dwight", 141);
		std::cout << "[BEFORE] " << b;
		b.decrementGrade(9);
		std::cout << "[DECR 9] " << b;
		b.decrementGrade();
		std::cout << "[DECR 1] " << b;
		
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}