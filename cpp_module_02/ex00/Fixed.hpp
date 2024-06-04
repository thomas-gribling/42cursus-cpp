#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	value;
		static int const	fractBits = 8;
		
	public:
		Fixed();
		Fixed(Fixed &source);
		~Fixed();

		Fixed &operator=(Fixed const &source);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif