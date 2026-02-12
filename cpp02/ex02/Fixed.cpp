#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : fixedPointValue(0){}

Fixed::Fixed(const Fixed& other){(*this) = other;}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int iValue){fixedPointValue = iValue << bits;}

Fixed::Fixed(const float floatValue) {fixedPointValue = roundf(floatValue * (1 << bits));}

int Fixed::getRawBits(void) const{return this->fixedPointValue;}

void Fixed::setRawBits(int const raw){
	this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return (float(fixedPointValue) / (1 << bits));
}

int Fixed::toInt(void) const {
	return (int(fixedPointValue >> bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}


bool Fixed::operator>(const Fixed &other) const {return this->toFloat() > other.toFloat();}

bool Fixed::operator<(const Fixed &other) const {return this->toFloat() < other.toFloat();}

bool Fixed::operator>=(const Fixed &other) const {return this->toFloat() >= other.toFloat();}

bool Fixed::operator<=(const Fixed &other) const {return this->toFloat() <= other.toFloat();}

bool Fixed::operator==(const Fixed &other) const {return this->toFloat() == other.toFloat();}

bool Fixed::operator!=(const Fixed &other) const {return this->toFloat() != other.toFloat();}

Fixed Fixed::operator+(const Fixed &other) const {return this->toFloat() + other.toFloat();}

Fixed Fixed::operator-(const Fixed &other) const {return this->toFloat() - other.toFloat();}

Fixed Fixed::operator*(const Fixed &other) const {return this->toFloat() * other.toFloat();}

Fixed Fixed::operator/(const Fixed &other) const {return this->toFloat() / other.toFloat();}

Fixed &Fixed::operator++(){
	this->fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed duplicated(*this);
	operator++();
	return (duplicated);
}

Fixed &Fixed::operator--(){
	this->fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed duplicated(*this);
	operator--();
	return (duplicated);
}

Fixed &Fixed::min(Fixed &fixedOne, Fixed &fixedTwo){
	if (fixedOne < fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}

const Fixed &Fixed::min(const Fixed &fixedOne, const Fixed &fixedTwo) {
	if (fixedOne < fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}

Fixed &Fixed::max(Fixed &fixedOne, Fixed &fixedTwo){
	if (fixedOne > fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}

const Fixed &Fixed::max(const Fixed &fixedOne, const Fixed &fixedTwo) {
	if (fixedOne > fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}
