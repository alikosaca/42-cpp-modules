#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("robot"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	(*this) = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other){
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){std::cout << "ClapTrap Destructor called" << std::endl;}

void ClapTrap::attack(const std::string& target){
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

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already destroyed (0 hit points) :/" << std::endl;
		return;
	}
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
	}
	else {
		this->hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage! Remaining hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hitPoints == 0 || this->energyPoints == 0){
		std::cout << "ClapTrap " << this->name << " has no energy or hit points to attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points! Remaining hit points: " << this->hitPoints << std::endl;
}
