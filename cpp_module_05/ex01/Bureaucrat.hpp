#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const _name;
		int	_grade;
	
	public:
		Bureaucrat();
		Bureaucrat( Bureaucrat const &src );
		Bureaucrat( std::string const name, int grade );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &src );

		void incrementGrade( int amt = 1 );
		void decrementGrade( int amt = 1 );
		void signForm( Form &f ) const;
		std::string const getName() const;
		int getGrade() const;

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
