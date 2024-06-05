#include "Cat.hpp"

Cat::Cat() {
	std::cout << "[CAT]: default constructor called." << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat( Cat const &src ): Animal( src ) {
	std::cout << "[CAT]: copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat() {
	delete brain;
	std::cout << "[CAT]: destructor called." << std::endl;
}


Cat &Cat::operator=( Cat const &src ) {
	type = src.type;
	if (brain)
		delete brain;
	brain = new Brain();
	return *this;
}