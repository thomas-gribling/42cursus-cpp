#include "Animal.hpp"

Animal::Animal() {
	std::cout << "[ANIMAL]: default constructor called." << std::endl;
}

Animal::Animal( Animal const &src ) {
	std::cout << "[ANIMAL]: copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout << "[ANIMAL]: destructor called." << std::endl;
}


Animal &Animal::operator=( Animal const &src ) {
	type = src.type;
	return *this;
}


void Animal::makeSound() const {
	std::cout << "Bip boup" << std::endl;
}

std::string Animal::getType() const {
	return type;
}