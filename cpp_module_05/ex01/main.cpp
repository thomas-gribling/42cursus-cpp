#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	std::cout << std::endl << "=== CONSTRUCTOR ===" << std::endl;
	try {
		Form f("Contrat", 100, 50);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f("Contrat", 151, 50);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form f("Contrat", 100, 0);
		std::cout << f;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== SIGNING ===" << std::endl;
	try {
		Form f("Contrat", 100, 50);
		Bureaucrat b("Patrick", 50);
		std::cout << f << b;
		f.beSigned(b);
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}