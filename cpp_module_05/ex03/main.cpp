#include "Intern.hpp"

int	main() {
	std::cout << std::endl << "=== INVALID FORM ===" << std::endl;

	Bureaucrat b("Admin", 1);
	Intern i;
	AForm *f = i.makeForm("NotExisitingForm", "Im doing a good work");

	std::cout << std::endl << "=== SHRUBBERY CREATION FORM ===" << std::endl;

	f = i.makeForm("ShrubberyCreationForm", "look_boss_I_drew_a_forest");
	try {
		b.signForm(*f);
		b.executeForm(*f);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl << "=== ROBOTOMY REQUEST FORM ===" << std::endl;

	f = i.makeForm("RobotomyRequestForm", "I robot");
	try {
		b.signForm(*f);
		b.executeForm(*f);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl << "=== PRESIDENTIAL PARDON FORM ===" << std::endl;

	f = i.makeForm("PresidentialPardonForm", "Mb bro");
	try {
		b.signForm(*f);
		b.executeForm(*f);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl;
	return 0;
}
