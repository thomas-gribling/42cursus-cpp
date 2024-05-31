#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "[CLAPTRAP]: " << "An unnamed trap has been placed!" << std::endl;
	_name = "MISSINGNO";
	_hp = 10;
	_ep = 10;
	_dmg = 0;
}

ClapTrap::ClapTrap( ClapTrap const &src ) {
	std::cout << "[CLAPTRAP]: " << src._name << " has been copied and placed!" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap( std::string name ) {
	std::cout << "[CLAPTRAP]: " << name << " has been placed!" << std::endl;
	_name = name;
	_hp = 10;
	_ep = 10;
	_dmg = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "[CLAPTRAP]: " << _name << " successfully destroyed!" << std::endl;
}


ClapTrap &ClapTrap::operator=( ClapTrap const &src) {
	_name = src._name;
	_hp = src._hp;
	_ep = src._ep;
	_dmg = src._dmg;
	return *this;
}


void ClapTrap::attack( const std::string &target ) {
	if (_hp && _ep) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _dmg << " points of damage!" << std::endl;
		_ep--;
	}
	else if (!_hp)
		std::cout << "ClapTrap " << _name << " failed to attack, it's broken." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " failed to attack, it's out of energy." << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (!_hp)
		std::cout << "ClapTrap " << _name << " is broken already." << std::endl;

	else {
		if ((int)_hp - (int)amount > 0) {
			std::cout << "ClapTrap " << _name << " has taken " << amount << " damages. It now has " << _hp - amount << " hp." << std::endl;
			_hp -= amount;
		}
		else {
			std::cout << "ClapTrap " << _name << " has taken " << amount << " damages. It broke!" << std::endl;
			_hp = 0;
		}
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (_hp && _ep) {
		std::cout << "ClapTrap " << _name << " repaired itself, gaining " << amount << " hit points. It now has " << _hp + amount << " hp." << std::endl;
		_ep--;
		_hp += amount;
	}
	else if (!_hp)
		std::cout << "ClapTrap " << _name << " failed to repair itself, it's broken." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " failed to repair itself, it's out of energy." << std::endl;
}