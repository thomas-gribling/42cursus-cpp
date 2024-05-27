#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	value;
		static int const	fractBits = 8;
		
	public:
		Fixed();
		Fixed(Fixed const &source);
		Fixed(int const int_n);
		Fixed(float const float_n);
		~Fixed();

		Fixed &operator=(Fixed const &source);
		Fixed operator+(Fixed const &source) const;
		Fixed operator-(Fixed const &source) const;
		Fixed operator*(Fixed const &source) const;
		Fixed operator/(Fixed const &source) const;
		Fixed &operator++(); //pre-increment
		Fixed operator++(int); //post-increment
		Fixed &operator--();
		Fixed operator--(int);
		bool operator>(Fixed const &source);
		bool operator<(Fixed const &source);
		bool operator>=(Fixed const &source);
		bool operator<=(Fixed const &source);
		bool operator==(Fixed const &source);
		bool operator!=(Fixed const &source);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int	toInt( void ) const;
		static Fixed &min( Fixed &a, Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif