#include "Point.hpp"

Point::Point(): x(0), y(0) {
	std::cout << "Point default constructor called" << std::endl;
};

Point::Point(const float x, const float y): x(x), y(y) {
	std::cout << "Point float constructor called" << std::endl;
};

Point &Point::operator=(const Point &point) {
	std::cout << "Point copy assignment operator called" << std::endl;
	if (this != &point) {
		const_cast<Fixed &>(this->x) = point.get_x();
		const_cast<Fixed &>(this->y) = point.get_y();
	}
	return *this;
}

Point::Point(const Point &point) {
	std::cout << "Point copy constructor called" << std::endl;
	*this = point;
};

Point::~Point() {
	std::cout << "Point destructor called" << std::endl;
}

const Fixed Point::get_x(void) const {
	return this->x;
}

const Fixed Point::get_y(void) const {
	return this->y;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
	return os << "x:" << point.get_x() << " y:" << point.get_y();
}