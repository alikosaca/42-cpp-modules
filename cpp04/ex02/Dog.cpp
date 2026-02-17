#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other){
	this->brain = new Brain();
	std::cout << "Dog Copy Constructor called" << std::endl;
	(*this) = other;
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog Copy assignment called" << std::endl;
	if (this != &other){
		this->type = other.type;
		AAnimal::operator=(other);
		delete brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const{ std::cout << "hav" << std::endl; }

Brain *Dog::getBrain() { return (this->brain); }
