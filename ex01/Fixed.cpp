#include "Fixed.hpp"


Fixed::Fixed(): fx_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixed.fx_point_value);
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->setRawBits(fixed.fx_point_value);
	}

	return *this;
}

Fixed::Fixed(const int raw): fx_point_value(raw << fx_point_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw): fx_point_value(std::roundf(raw * (1 << fx_point_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->fx_point_value) / (1 << this->fx_point_bits);
}

int Fixed::toInt(void) const {
	return this->fx_point_value >> this->fx_point_bits;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return this->fx_point_value;
}

void Fixed::setRawBits(int raw) {
	this->fx_point_value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return os << fixed.toFloat();
}