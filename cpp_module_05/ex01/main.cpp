#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	std::cout << std::endl << "=== CONSTRUCTOR ===" << std::endl;
	try {
		Form f("Contrat", 100, 50);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Form f("Contrat", 151, 50);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Form f("Contrat", 100, 0);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== SIGNING ===" << std::endl;
	try {
		Form f("Contrat", 100, 50);
		Bureaucrat b("Boris", 100);
		std::cout << f << b;
		b.signForm(f);
		std::cout << f;
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form f("Contrat", 100, 50);
		Bureaucrat b("Maurice", 101);
		std::cout << f << b;
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
