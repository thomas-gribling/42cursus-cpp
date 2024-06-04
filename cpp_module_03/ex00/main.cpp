#include "ClapTrap.hpp"

int	main() {
	ClapTrap Pain("Paint au chocolat");
	ClapTrap Choc("Chocolatine");

	std::cout << std::endl;

	Pain.takeDamage(3);
	Choc.takeDamage(6);
	std::cout << std::endl;
	Choc.beRepaired(6);
	Pain.beRepaired(2);
	std::cout << std::endl;
	Choc.takeDamage(42);
	Choc.attack("Pain au chocolat");
	Pain.attack("Chocolatine");
	std::cout << std::endl;
	Choc.takeDamage(42);

	std::cout << std::endl;

	return 0;
}