#include "Cat.hpp"

Cat::Cat() : AAnimal(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other){
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->brain = new Brain();
	(*this) = other;
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other){
		this->type = other.type;
		AAnimal::operator=(other);
		delete brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat(){
		delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{ std::cout << "miav" << std::endl; }

Brain *Cat::getBrain() { return (this->brain); }
