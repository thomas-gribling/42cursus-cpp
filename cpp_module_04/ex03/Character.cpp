#include "Character.hpp"

Character::Character() {}

Character::Character( Character const &src ): ICharacter( src ) {
	name = src.name;
	for (int i = 0; i < 4; i++)
		inv[i] = src.inv[i];
}

Character::~Character() {}


Character &Character::operator=( Character const &src ) {
	name = src.name;
	for (int i = 0; i < 4; i++)
		inv[i] = src.inv[i];
	return *this;
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
		std::cout << "Item \"" << m->getType() << "\" stored in " << name << "'s inventory." << std::endl;
	else
		std::cout << "Player " << name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		std::cout << "Index out of bounds! (0 - 3)" << std::endl;

	else if (!inv[idx])
		std::cout << "Inventory slot is empty!" << std::endl;

	else {
		std::cout << "Item \"" << inv[idx]->getType() << "\" successfully unequiped by " << name << "." << std::endl;
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