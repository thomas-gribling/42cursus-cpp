#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(Fixed &source) {
	std::cout << "Copy constructor called" << std::endl;
	value = source.value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(Fixed const &source) {
	std::cout << "Copy assignment operator called" << std::endl;
	value = source.getRawBits();
	return *this;
}


int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}