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
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif