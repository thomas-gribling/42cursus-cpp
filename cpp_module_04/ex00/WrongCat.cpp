#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "[WRONGCAT]: default constructor called." << std::endl;
	type = "Cat";
}

WrongCat::WrongCat( WrongCat const &src ): WrongAnimal( src ) {
	std::cout << "[WRONGCAT]: copy constructor called." << std::endl;
	type = src.type;
}

WrongCat::~WrongCat() {
	std::cout << "[WRONGCAT]: destructor called." << std::endl;
}


WrongCat &WrongCat::operator=( WrongCat const &src ) {
	type = src.type;
	return *this;
}


void WrongCat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}