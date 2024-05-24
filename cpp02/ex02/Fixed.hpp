#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		int	value;
		static int const	fractBits = 8;
		
	public:
		Fixed();
		Fixed(Fixed const &source);
		Fixed(int const int_n);
		Fixed(float const float_n);
		~Fixed();

		Fixed &operator=(Fixed const &source);
		Fixed &operator+(Fixed const &source);
		Fixed &operator-(Fixed const &source);
		Fixed &operator*(Fixed const &source);
		Fixed &operator/(Fixed const &source);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif