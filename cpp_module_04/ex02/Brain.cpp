#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[BRAIN]: default constructor called." << std::endl;
}

Brain::Brain( Brain const &src ) {
	std::cout << "[BRAIN]: copy constructor called." << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "[BRAIN]: destructor called." << std::endl;
}


Brain &Brain::operator=( Brain const &src ) {
	(void)src;
	return *this;
}