#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat Copy Constructor called" << std::endl;
	(*this) = other;
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(){ std::cout << "Cat Destructor called" << std::endl; }

void Cat::makeSound() const{
	std::cout << "miav" << std::endl;
}
