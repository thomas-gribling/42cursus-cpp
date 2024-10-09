#include "Intern.hpp"

int	main() {
	Bureaucrat Admin("Admin", 1);
	Intern Gaspard;
	AForm *Contract;

	Contract = Gaspard.makeForm("Shrubbery", "haha");
	Contract->beSigned(Admin);
	Contract->execute(Admin);
	return 0;
}
