#include "Animal.hpp"

Animal::Animal(){
	this->type = "Parent";
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "Animal Copy Constructor called" << std::endl;
	(*this) = other;
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal(){ std::cout << "Animal Destructor called" << std::endl; }

void Animal::makeSound() const{
	std::cout << "Im Animal" << std::endl;
}

std::string Animal::getType() const{
	return this->type;
}