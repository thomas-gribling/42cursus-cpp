#include "Fixed.hpp"

int	main () {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 7.7f ) - Fixed( 2 ) + Fixed( 3.14f ));
	Fixed const d( Fixed( c ) / Fixed( 2 ) + Fixed( 38 ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << b << std::endl << std::endl;

	std::cout << c << std::endl << std::endl;

	std::cout << d << std::endl << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl << std::endl;

	std::cout << (a < Fixed( 1 )) << std::endl;
	std::cout << (a > Fixed( 1 )) << std::endl;
	std::cout << (a <= Fixed( 1 )) << std::endl;
	std::cout << (a >= Fixed( 1 )) << std::endl;
	std::cout << (a == Fixed( 1 )) << std::endl;
	std::cout << (a != Fixed( 1 )) << std::endl;
	return 0;
}