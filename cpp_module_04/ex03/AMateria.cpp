#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {}

AMateria::AMateria( AMateria const &src ) {
	type = src.type;
}

AMateria::AMateria( std::string const &type ) {
	this->type = type;
}

AMateria::~AMateria() {}


AMateria &AMateria::operator=( AMateria const &src ) {
	type = src.type;
	return *this;
}


std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* an item is used on " << target.getName() << "... but nothing happened *" << std::endl;
}