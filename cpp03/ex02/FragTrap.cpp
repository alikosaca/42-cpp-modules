#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->name = "fabri";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap Copy constructor called" << std::endl;
	(*this) = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap(){std::cout << "FragTrap Destructor called" << std::endl;}

void FragTrap::highFivesGuys() {std::cout << this->name << " wants to give everyone a high five! Any takers?" << std::endl;}