#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "[WRONGANIMAL]: default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) {
	std::cout << "[WRONGANIMAL]: copy constructor called." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WRONGANIMAL]: destructor called." << std::endl;
}


WrongAnimal &WrongAnimal::operator=( WrongAnimal const &src ) {
	type = src.type;
	return *this;
}


void WrongAnimal::makeSound() const {
	std::cout << "Bip boup" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}