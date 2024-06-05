#include "Dog.hpp"

Dog::Dog() {
	std::cout << "[DOG]: default constructor called." << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog( Dog const &src ): Animal( src ) {
	std::cout << "[DOG]: copy constructor called." << std::endl;
	type = src.type;
	brain = new Brain(*(src.brain));
}

Dog::~Dog() {
	delete brain;
	std::cout << "[DOG]: destructor called." << std::endl;
}


Dog &Dog::operator=( Dog const &src ) {
	type = src.type;
	if (brain)
		delete brain;
	brain = new Brain();
	return *this;
}


void Dog::makeSound() const {
	std::cout << "Ouaf" << std::endl;
}