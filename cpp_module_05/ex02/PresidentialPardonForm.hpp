#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string const _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const &src );
		PresidentialPardonForm( std::string const target );
		~PresidentialPardonForm();

		void executeSpecial() const;

		PresidentialPardonForm &operator=( PresidentialPardonForm const &src );
};

#endif // PRESIDENTIALPARDONFORM_HPP