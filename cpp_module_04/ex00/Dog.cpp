#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[DOG]: default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog( Dog const &src ): Animal( src ) {
	std::cout << "[DOG]: copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "[DOG]: destructor called." << std::endl;
}


Dog &Dog::operator=( Dog const &src ) {
	type = src.type;
	return *this;
}