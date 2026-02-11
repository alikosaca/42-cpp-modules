#ifndef FIXED_HPP
# define FIXED_HPP


#include <string>
#include <iostream>
#include <cmath>

class Fixed{
	private:
		int fixedPointValue;
		static const int bits;
	public:
		Fixed();
		Fixed(const int iValue);
		Fixed(const float fValue);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif