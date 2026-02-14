#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->name = "atiba";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	(*this) = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap(){std::cout << "ScavTrap Destructor called" << std::endl;}

void ScavTrap::attack(const std::string& target){
	if (this->hitPoints == 0){
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	else if (this->energyPoints == 0){
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (hitPoints == 0)
		std::cout << "ScavTrap " << this->name << " is dead and cannot be Gate keeper!" << std::endl;
	else
    	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
