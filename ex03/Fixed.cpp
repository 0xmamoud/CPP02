#include "Fixed.hpp"

Fixed::Fixed(): fx_point_value(0) {
	// std::cout << " Fixed default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &fixed) {
	// std::cout << "Fixed copy constructor called" << std::endl;
	this->setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Fixed copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->setRawBits(fixed.getRawBits());
	}

	return *this;
}

Fixed::Fixed(const int raw): fx_point_value(raw << fx_point_bits) {
	// std::cout << "Fixed int constructor called" << std::endl;
}

Fixed::Fixed(const float raw): fx_point_value(std::roundf(raw * (1 << fx_point_bits))) {
	// std::cout << "Fixed float constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Fixed destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->getRawBits()) / (1 << this->fx_point_bits);
}

int Fixed::toInt(void) const {
	return this->getRawBits() >> this->fx_point_bits;
}


int Fixed::getRawBits(void) const {
	return this->fx_point_value;
}

void Fixed::setRawBits(int raw) {
	this->fx_point_value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	return os << fixed.toFloat();
}

bool Fixed::operator>(const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->getRawBits() < fixed.getRawBits();	
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
	return this->getRawBits() == fixed.getRawBits();	
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return this->fx_point_value + fixed.fx_point_value;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return this->fx_point_value - fixed.fx_point_value;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return this->toFloat() * fixed.toFloat();	
}

Fixed Fixed::operator/(const Fixed &fixed) const {	
	return this->toFloat() / fixed.toFloat();
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++this->fx_point_value;
	return tmp;
}

Fixed &Fixed::operator++(void) {
	++this->fx_point_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--this->fx_point_value;
	return tmp;
}

Fixed &Fixed::operator--(void) {
	--this->fx_point_value;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits()) 
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits()) 
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits()) 
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits()) 
		return b;
	return a;
}