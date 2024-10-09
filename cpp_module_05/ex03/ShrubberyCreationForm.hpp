#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string const _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const &src );
		ShrubberyCreationForm( std::string const target );
		~ShrubberyCreationForm();

		void executeSpecial() const;

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &src );

		class OpenFileException: public std::exception {
			virtual const char* what() const throw();
		};
};

#endif // SHRUBBERYCREATIONFORM_HPP