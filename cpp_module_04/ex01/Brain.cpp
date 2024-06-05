#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[BRAIN]: default constructor called." << std::endl;
}

Brain::Brain( Brain const &src ) {
	std::cout << "[BRAIN]: copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain::~Brain() {
	std::cout << "[BRAIN]: destructor called." << std::endl;
}


Brain &Brain::operator=( Brain const &src ) {
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return *this;
}