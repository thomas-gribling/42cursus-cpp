#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _isSigned;
		int const _toSign;
		int const _toExec;

	protected:
		AForm();
		AForm( AForm const &src );
		AForm( std::string const name, int const toSign, int const toExec );
		virtual void executeSpecial() const = 0;

	public:
		~AForm();

		AForm &operator=( AForm const &src );

		void beSigned( Bureaucrat const &b );
		std::string const getName() const;
		bool getIsSigned() const;
		int getToSign() const;
		int getToExec() const;
		void execute(Bureaucrat const & executor) const;

		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};

		class AlreadySignedException: public std::exception {
			virtual const char* what() const throw();
		};

		class MustBeSignedException: public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP
