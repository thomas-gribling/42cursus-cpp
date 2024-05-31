#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "[SCAVTRAP]: " << "An unnamed trap has been placed!" << std::endl;
	_name = "MISSINGNO";
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	_guard = false;
}

ScavTrap::ScavTrap( ScavTrap const &src ): ClapTrap( src ) {
	std::cout << "[SCAVTRAP]: " << src._name << " has been copied and placed!" << std::endl;
	*this = src;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap ( name ) {
	std::cout << "[SCAVTRAP]: " << name << " has been placed!" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	_guard = false;
}

ScavTrap::~ScavTrap() {
	std::cout << "[SCAVTRAP]: " << _name << " successfully destroyed!" << std::endl;
}


ScavTrap &ScavTrap::operator=( ScavTrap const &src) {
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
	_guard = src._guard;
	return *this;
}


void ScavTrap::attack( const std::string &target ) {
	if (_hp && _ep) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!" << std::endl;
		_ep--;
	}
	else if (!_hp)
		std::cout << "ScavTrap " << _name << " failed to attack, it's broken." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " failed to attack, it's out of energy." << std::endl;
}

void	ScavTrap::guardGate() {
	_guard = !_guard;

	if (_guard)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is not in Gate keeper mode anymore." << std::endl;
}