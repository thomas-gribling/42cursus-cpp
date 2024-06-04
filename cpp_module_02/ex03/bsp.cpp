#include "Point.hpp"

bool	bsp( Point const &a, Point const &b, Point const &c, Point const &point ) {
	bool	detec[3];

	detec[0] = (((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX()))) > 0;
	detec[1] = (((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX()))) > 0;
	detec[2] = (((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX()))) > 0;
	return detec[0] && detec[1] && detec[2];
}