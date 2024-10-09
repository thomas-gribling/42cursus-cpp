#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( Intern const &src ) {
	(void)src;
}

Intern::~Intern() {}


static AForm *makeShrubbery( std::string const target ) {
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy( std::string const target ) {
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidential( std::string const target ) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm( std::string const name, std::string const target ) const {
	AForm *(*forms_const[3])(std::string const target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
	std::string forms_names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++) {
		if (name == forms_names[i]) {
			std::cout << "Intern creates " << name << "." << std::endl;
			return forms_const[i](target);
		}
	}
	std::cerr << "Intern couldn't create " << name << " because \"It doesn't exist!\". Who the hell hired this guy? He's fired!" << std::endl;
	return NULL;
}


Intern &Intern::operator=( Intern const &src ) {
	(void)src;
	return *this;
}