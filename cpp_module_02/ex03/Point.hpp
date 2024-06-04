#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		Point();
		Point( float const x, float const y );
		Point( Point const &src );
		~Point();

		Fixed const &getX() const;
		Fixed const &getY() const;

		Point &operator=( Point const &src );
		Point &operator-( Point const &src );
		Point &operator*( Point const &src );
};

bool	bsp( Point const &a, Point const &b, Point const &c, Point const &point );

#endif