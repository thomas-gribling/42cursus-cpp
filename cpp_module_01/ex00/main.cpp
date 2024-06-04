#include "Zombie.hpp"

int	main() {
	Zombie	*z_heap = newZombie("Pierre DE LA HEAP");
	
	z_heap->announce();
	randomChump("Pedro DE LA STACK");
	delete z_heap;
	return 0;
}