#ifndef FIXED_HPP
# define FIXED_HPP


#include <string>
#include <iostream>

class Fixed{
	private:
		int fixedPointValue;
		static const int bits;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

#endif