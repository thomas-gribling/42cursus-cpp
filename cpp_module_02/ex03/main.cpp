#include "Point.hpp"

void	testPoint( Point const &a, Point const &b, Point const &c, Point const &p ) {
	if (bsp(a, b, c, p))
		std::cout << "Le point est dans le triangle!" << std::endl;
	else
		std::cout << "Le point n'est pas dans le triangle!" << std::endl;
}

int	main () {
	Point const a(0, 10);
	Point const b(-5, 0);
	Point const c(5,  0);

	testPoint(a, b, c, Point(3,  3)); // dedans
	testPoint(a, b, c, Point(10, 0));
	testPoint(a, b, c, Point(-3, 5));
	testPoint(a, b, c, Point(6,  9));
	testPoint(a, b, c, Point(1,  1)); // dedans
	testPoint(a, b, c, Point(0, 10));

	return 0;
}