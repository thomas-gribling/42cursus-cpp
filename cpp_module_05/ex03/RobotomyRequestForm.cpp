#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("MISSINGNO") {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) : AForm("RobotomyRequestForm", 72, 45), _target(src._target) {}

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeSpecial() const {
	std::cout << _target;
	if (std::rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << "'s robotomization has failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &src ) {
	if (this == &src)
		return *this;
	return *this;
}