#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "[DIAMONDTRAP]: " << "An unnamed trap has been placed!" << std::endl;
	_name = "MISSINGNO";
	ClapTrap::_name = "MISSINGNO_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ): ScavTrap( src ), FragTrap( src ) {
	std::cout << "[DIAMONDTRAP]: " << src._name << " has been copied and placed!" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap( std::string name ): ScavTrap ( name ), FragTrap( name ) {
	std::cout << "[DIAMONDTRAP]: " << name << " has been placed!" << std::endl;
	_name = name;
	ScavTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DIAMONDTRAP]: " << _name << " successfully destroyed!" << std::endl;
}


DiamondTrap &DiamondTrap::operator=( DiamondTrap const &src) {
	_name = src._name;
	ClapTrap::_name = src._name + "_clap_name";
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_dmg = src._dmg;
	return *this;
}


void DiamondTrap::whoAmI() {
	std::cout << "Hi guys! I'm " << _name << "! Pssst, keep it for yourself but... my secret name is " << ClapTrap::_name << "." << std::endl;
}