#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fx_point_value;
		static const int fx_point_bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed();

		float toFloat(void) const;
		int	toInt(void) const;
		
		int getRawBits(void ) const;
		void setRawBits(const int raw);
		
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed operator++(int);
		Fixed &operator++(void);
		Fixed operator--(int);
		Fixed &operator--(void);

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif