#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	if (this != &other) {
		std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
		(*this) = other;
	}
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->type = other.type;
		std::cout << "WrongAnimal Copy Assignment Constructor Called" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}
