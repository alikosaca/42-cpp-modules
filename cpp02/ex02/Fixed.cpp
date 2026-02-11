#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	(*this) = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int iValue){
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = iValue << bits;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(floatValue * (1 << bits));
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

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
