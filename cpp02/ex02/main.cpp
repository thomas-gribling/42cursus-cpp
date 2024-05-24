#include "Fixed.hpp"

int	main () {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 7.7f ) - Fixed( 2 ) + Fixed( 3.14f ));
	Fixed const d( Fixed( 84.84f ) / Fixed( 2 ));

	std::cout << "a:" << std::endl;
	std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << std::endl << "b:" << std::endl;
	std::cout << b << std::endl;
	//std::cout << --b << std::endl;
	std::cout << b << std::endl;
	//std::cout << b-- << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl << "c:" << std::endl;
	std::cout << c << std::endl;

	std::cout << std::endl << "d:" << std::endl;
	std::cout << d << std::endl;

	//std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}