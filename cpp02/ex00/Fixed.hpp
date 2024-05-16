#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed &source);
		~Fixed();

		Fixed &operator=(Fixed &source);
};

#endif