#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		saved[i] = 0;
}

MateriaSource::MateriaSource( MateriaSource const &src ) {
	for (int i = 0; i < 4; i++) {
		if (saved[i])
			saved[i] = src.saved[i]->clone();
		else
			saved[i] = 0;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (saved[i])
			delete saved[i];
}


MateriaSource &MateriaSource::operator=( MateriaSource const &src ) {
	for (int i = 0; i < 4; i++) {
		if (saved[i])
			saved[i] = src.saved[i]->clone();
		else
			saved[i] = 0;
	}
	return *this;
}


void MateriaSource::learnMateria(AMateria *m) {
	int stored = 0;

	if (!m) {
		std::cout << "Nothing to learn!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!saved[i]) {
			saved[i] = m->clone();
			stored = 1;
			break;
		}
	}
	if (stored)
		std::cout << "MateriaSource has learned \"" << m->getType() << "\"." << std::endl;
	else
		std::cout << "MateriaSource cannot learn anything more!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (saved[i] && saved[i]->getType() == type) {
			std::cout << "Materia \"" << type << "\" created from knowledge." << std::endl;
			return saved[i]->clone();
		}
	}
	std::cout << "Unknown Materia \"" << type << "\"." << std::endl;
	return 0;
}