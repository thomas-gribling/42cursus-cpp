#include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter( ICharacter const &src ) {
	name = src.name;
	for (int i = 0; i < 4; i++)
		inv[i] = src.inv[i];
}

ICharacter::~ICharacter() {}


ICharacter &ICharacter::operator=( ICharacter const &src ) {
	name = src.name;
	for (int i = 0; i < 4; i++)
		inv[i] = src.inv[i];
	return *this;
}