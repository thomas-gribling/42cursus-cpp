#include "Character.hpp"

Character::Character() {
	name = "MISSINGNO";
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
}

Character::Character( Character const &src ) {
	name = src.name;
	for (int i = 0; i < 4; i++) {
		if (inv[i])
			inv[i] = src.inv[i]->clone();
		else
			inv[i] = 0;
	}
}

Character::Character( std::string name ) {
	this->name = name;
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (inv[i])
			delete inv[i];
}


Character &Character::operator=( Character const &src ) {
	name = src.name;
	for (int i = 0; i < 4; i++) {
		if (inv[i])
			inv[i] = src.inv[i]->clone();
		else
			inv[i] = 0;
	}
	return *this;
}


std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	int stored = 0;

	if (!m) {
		std::cout << "Nothing to equip!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!inv[i]) {
			inv[i] = m;
			stored = 1;
			break;
		}
	}
	if (stored)
		std::cout << "Materia \"" << m->getType() << "\" stored in " << name << "'s inventory." << std::endl;
	else
		std::cout << name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds! (0 - 3)" << std::endl;

	else if (!inv[idx])
		std::cout << "Inventory slot is empty!" << std::endl;

	else {
		std::cout << "Materia \"" << inv[idx]->getType() << "\" successfully unequiped by " << name << "." << std::endl;
		inv[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds! (0 - 3)" << std::endl;

	else if (!inv[idx])
		std::cout << "Inventory slot is empty!" << std::endl;
	
	else
		inv[idx]->use(target);
}