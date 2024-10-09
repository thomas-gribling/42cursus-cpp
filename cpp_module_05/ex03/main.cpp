#include "Intern.hpp"

int	main() {
	std::cout << std::endl << "=== INVALID FORM ===" << std::endl;

	Bureaucrat b("Admin", 1);
	Intern i;
	AForm *f = i.makeForm("NotExisitingForm", "Im doing a good work");

	std::cout << std::endl << "=== SHRUBBERY CREATION FORM ===" << std::endl;

	f = i.makeForm("ShrubberyCreationForm", "look_boss_I_drew_a_tree");
	try {
		f->beSigned(b);
		b.signForm(*f);
		b.executeForm(*f);
		f->execute(b);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl << "=== ROBOTOMY REQUEST FORM ===" << std::endl;

	f = i.makeForm("RobotomyRequestForm", "I robot");
	try {
		f->beSigned(b);
		b.signForm(*f);
		b.executeForm(*f);
		f->execute(b);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl << "=== PRESIDENTIAL PARDON FORM ===" << std::endl;

	f = i.makeForm("PresidentialPardonForm", "Mb bro");
	try {
		f->beSigned(b);
		b.signForm(*f);
		b.executeForm(*f);
		f->execute(b);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete f;

	std::cout << std::endl;
	return 0;
}
