#include "Cure.hpp"

Cure::Cure() {
	type = "cure";
}

Cure::Cure( Cure const &src ): AMateria( src ) {
	type = src.type;
}

Cure::~Cure() {}


Cure &Cure::operator=( Cure const &src ) {
	type = src.type;
	return *this;
}


Cure *Cure::clone() const {
	Cure *cure = new Cure();

	return cure;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}