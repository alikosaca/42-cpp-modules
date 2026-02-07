#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){}
HumanB::HumanB(std::string name, Weapon* weapon) : name(name), weapon(weapon){}

HumanB::~HumanB(){
	std::cout << this->name << " died" << std::endl;
}

void HumanB::attack(void) const{
	if (weapon)
		std::cout << "attacks with " << this->weapon->getType() << std::endl;
	else
		std::cout << "we dont have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}
