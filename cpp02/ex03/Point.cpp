#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point( float const x, float const y ): _x(x), _y(y) {}

Point::Point( Point const &src ) {
	*this = src;
}

Point::~Point() {}


Fixed const &Point::getX() const {
	return _x;
}

Fixed const &Point::getY() const {
	return _y;
}


Point &Point::operator=( Point const &src ) {
	(void)src;
	return *this;
}