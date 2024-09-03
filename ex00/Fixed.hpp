#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		int fx_point_value;
		static const int fx_point_bits;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits(void ) const;
		void setRawBits(const int raw);
};

#endif