#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap trap("Trap");
	DiamondTrap anotherTrap;

	std::cout << std::endl;

	trap.printTrap();
	trap.attack("MISSINGNO");
	trap.whoAmI();
	std::cout << std::endl;
	anotherTrap.printTrap();
	anotherTrap.whoAmI();

	std::cout << std::endl;

	return 0;
}