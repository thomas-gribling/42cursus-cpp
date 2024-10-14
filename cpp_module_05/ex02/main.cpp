#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	std::cout << std::endl << "=== SHRUBBERYCREATIONFORM ===" << std::endl;
	try {
		ShrubberyCreationForm f("kokiri_forest");
		Bureaucrat b("Raoul", 140);

		std::cout << f << b;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		ShrubberyCreationForm f("kokiri_forest");
		Bureaucrat b("Raoul", 130);

		std::cout << std::endl << f << b;
		b.executeForm(f);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		ShrubberyCreationForm f("kokiri_forest");
		Bureaucrat b("Roger", 130);

		std::cout << std::endl << f << b;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== ROBOTOMYREQUESTFORM ===" << std::endl;
	try {
		RobotomyRequestForm f("Gustave");
		Bureaucrat b("Pierre-Paul Jacques", 45);

		std::cout << f << b;
		b.signForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "=== PRESIDENTIALPARDONFORM ===" << std::endl;
	try {
		PresidentialPardonForm f("Alfonzo");
		Bureaucrat b("Manu", 1);

		std::cout << f << b;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
