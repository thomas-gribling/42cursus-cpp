#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	{
		std::cout << "== HumanA test ==" << std::endl;
		Weapon club = Weapon("kokiri sword");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("master sword");
		bob.attack();
	}

	{
		std::cout << std::endl << "== HumanB test ==" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}