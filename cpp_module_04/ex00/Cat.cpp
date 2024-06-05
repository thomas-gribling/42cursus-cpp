#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[CAT]: default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat( Cat const &src ): Animal( src ) {
	std::cout << "[CAT]: copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << "[CAT]: destructor called." << std::endl;
}


Cat &Cat::operator=( Cat const &src ) {
	type = src.type;
	return *this;
}


void Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}