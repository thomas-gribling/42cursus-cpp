#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "[FRAGTRAP]: " << "An unnamed trap has been placed!" << std::endl;
	_name = "MISSINGNO";
	_hp = 100;
	_ep = 100;
	_dmg = 30;
}

FragTrap::FragTrap( FragTrap const &src ): ClapTrap( src ) {
	std::cout << "[FRAGTRAP]: " << src._name << " has been copied and placed!" << std::endl;
	*this = src;
}

FragTrap::FragTrap( std::string name ): ClapTrap ( name ) {
	std::cout << "[FRAGTRAP]: " << name << " has been placed!" << std::endl;
	_name = name;
	_hp = 100;
	_ep = 100;
	_dmg = 30;
}

FragTrap::~FragTrap() {
	std::cout << "[FRAGTRAP]: " << _name << " successfully destroyed!" << std::endl;
}


FragTrap &FragTrap::operator=( FragTrap const &src) {
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " wants a high five! *clap sound*" << std::endl;
}
