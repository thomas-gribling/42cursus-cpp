#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( Intern const &src ) {
	(void)src;
}

Intern::~Intern() {}


AForm *Intern::makeForm( std::string const name, std::string const target ) const {

}


Intern &Intern::operator=( Intern const &src ) {
	(void)src;
	return *this;
}