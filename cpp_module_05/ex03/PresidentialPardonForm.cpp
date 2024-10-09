#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("MISSINGNO") {}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src ) : AForm("PresidentialPardonForm", 25, 5), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeSpecial() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &src ) {
	(std::string)_target = src._target;
	return *this;
}