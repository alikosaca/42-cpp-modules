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


		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& fixedOne, Fixed& fiexTwo);
		static const Fixed& min(const Fixed& fixedOne, const Fixed& fiexTwo);
		static Fixed& max(Fixed& fixedOne, Fixed& fiexTwo);
		static const Fixed& max(const Fixed& fixedOne, const Fixed& fiexTwo);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif