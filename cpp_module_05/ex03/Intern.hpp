#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern( Intern const &src );
		~Intern();

		AForm *makeForm( std::string const name, std::string const target ) const;
		Intern &operator=( Intern const &src );
};

#endif // INTERN_HPP