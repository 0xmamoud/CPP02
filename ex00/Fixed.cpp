#include "Fixed.hpp"

const int Fixed::fx_point_bits = 8;

Fixed::Fixed(): fx_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->setRawBits(fixed.getRawBits());
	}

	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;

	return this->fx_point_value;
}

void Fixed::setRawBits(int raw) {
	this->fx_point_value = raw;
}