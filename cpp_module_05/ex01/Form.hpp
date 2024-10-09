#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _isSigned;
		int const _toSign;
		int const _toExec;

	public:
		Form();
		Form( Form const &src );
		Form( std::string const name, int const toSign, int const toExec );
		~Form();

		Form &operator=( Form const &src );

		void beSigned( Bureaucrat const &b );
		std::string const getName() const;
		bool getIsSigned() const;
		int getToSign() const;
		int getToExec() const;

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};

		class AlreadySignedException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
