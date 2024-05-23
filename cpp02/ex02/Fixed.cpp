#include "Fixed.hpp"

Fixed::Fixed() {
	//std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(Fixed const &source) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed::Fixed(int const int_n) {
	//std::cout << "Int constructor called" << std::endl;
	value = int_n * pow(2, fractBits);
}

Fixed::Fixed(float const float_n) {
	//std::cout << "Float constructor called" << std::endl;
	value = (int)(float_n * pow(2, fractBits));
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(Fixed const &source) {
	//std::cout << "Copy assignment operator called" << std::endl;
	value = source.value;
	return *this;
}

Fixed &Fixed::operator+(Fixed const &source) {
	value += source.value;
	return *this;
}

Fixed &Fixed::operator-(Fixed const &source) {
	value -= source.value;
	return *this;
}

Fixed &Fixed::operator*(Fixed const &source) {
	value *= source.value;
	return *this;
}

Fixed &Fixed::operator/(Fixed const &source) {
	value /= source.value;
	return *this;
}

Fixed &Fixed::operator++() {}

Fixed Fixed::operator++(int) {}

Fixed &Fixed::operator--() {}

Fixed Fixed::operator--(int) {}

bool Fixed::operator>(Fixed const &source) {
	return value > source.value;
}

bool Fixed::operator<(Fixed const &source) {
	return value < source.value;
}

bool Fixed::operator>=(Fixed const &source) {
	return value >= source.value;
}

bool Fixed::operator<=(Fixed const &source) {
	return value <= source.value;
}

bool Fixed::operator==(Fixed const &source) {
	return value == source.value;
}

bool Fixed::operator!=(Fixed const &source) {
	return value != source.value;
}


int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float	Fixed::toFloat( void ) const {
	return value / pow(2, fractBits);
}

int	Fixed::toInt( void ) const {
	return (int)(value / pow(2, fractBits));
}


std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}