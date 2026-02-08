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

/*
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>*/