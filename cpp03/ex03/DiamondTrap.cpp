#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "[DIAMONDTRAP]: " << "An unnamed trap has been placed!" << std::endl;
	_name = "MISSINGNO";
	ClapTrap::_name = "MISSINGNO_clap_name";
	this->_hp = FragTrap::defaultHp;
	this->_ep = ScavTrap::defaultEP;
	this->_dmg = FragTrap::defaultDmg;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ): ClapTrap( src ), ScavTrap( src ), FragTrap( src ) {
	std::cout << "[DIAMONDTRAP]: " << src._name << " has been copied and placed!" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap( name ), ScavTrap ( name ), FragTrap( name ) {
	std::cout << "[DIAMONDTRAP]: " << name << " has been placed!" << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::defaultHp;
	this->_ep = ScavTrap::defaultEP;
	this->_dmg = FragTrap::defaultDmg;
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


void DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "Hi guys! I'm " << _name << "! Pssst, keep it for yourself but... my full name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::printTrap() {
	std::cout << "name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "HP: " << _hp << std::endl;
	std::cout << "EP: " << _ep << std::endl;
	std::cout << "DMG: " << _dmg << std::endl;
}