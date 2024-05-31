#include "ScavTrap.hpp"

int	main() {
	ScavTrap Kokiri("Kokiri Sword");
	ScavTrap Master("Master Sword");

	std::cout << std::endl;

	Kokiri.attack("Master Sword");
	Master.attack("Kokiri Sword");
	Kokiri.guardGate();
	Kokiri.guardGate();

	std::cout << std::endl;

	return 0;
}