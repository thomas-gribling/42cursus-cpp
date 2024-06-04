#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap) : _name(name), _weapon(weap) {}
HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}