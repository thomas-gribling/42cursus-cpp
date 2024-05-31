#include "FragTrap.hpp"

int	main() {
	FragTrap Winners("Stack");
	FragTrap Loosers("Heap");

	std::cout << std::endl;

	Winners.highFivesGuys();
	std::cout << "No high five for the heap." << std::endl;

	std::cout << std::endl;

	return 0;
}