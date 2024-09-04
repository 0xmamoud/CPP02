#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point();

		const Fixed get_x(void) const;
		const Fixed get_y(void) const;
};

std::ostream &operator<<(std::ostream &os, const Point &point);

#endif