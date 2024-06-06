#include "Ice.hpp"

Ice::Ice() {
	type = "ice";
}

Ice::Ice( Ice const &src ): AMateria( src ) {
	type = src.type;
}

Ice::~Ice() {}


Ice &Ice::operator=( Ice const &src ) {
	type = src.type;
	return *this;
}


Ice *Ice::clone() const {
	Ice *ice = new Ice();

	return ice;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}