#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
		const Point a;
		const Point b(4, 0);
		const Point c = Point(2, 4);
		const Point point(2, 2);

		std::cout << "my a point are " << a	<< std::endl;
		std::cout << "my b point are " << b	<< std::endl;
		std::cout << "my c point are " << c	<< std::endl;
		std::cout << "my point to check have " << point	<< std::endl;

		std::cout << "Point is in triangle: " << bsp(a, b, c, point) << std::endl;

	return 0;
}