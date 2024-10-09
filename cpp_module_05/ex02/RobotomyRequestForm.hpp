#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string const _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const &src );
		RobotomyRequestForm( std::string const target );
		~RobotomyRequestForm();

		void executeSpecial() const;

		RobotomyRequestForm &operator=( RobotomyRequestForm const &src );
};

#endif // ROBOTOMYREQUESTFORM_HPP