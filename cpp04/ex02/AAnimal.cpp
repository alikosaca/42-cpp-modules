#include "AAnimal.hpp"

AAnimal::AAnimal(){
	this->type = "Parent";
	std::cout << "Animal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other){
	std::cout << "Animal Copy Constructor called" << std::endl;
	(*this) = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal(){ std::cout << "Animal Destructor called" << std::endl; }

void AAnimal::makeSound() const{
	std::cout << "Im Animal" << std::endl;
}

std::string AAnimal::getType() const{
	return this->type;
}