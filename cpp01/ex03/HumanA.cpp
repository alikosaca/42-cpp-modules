#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon){}

HumanA::~HumanA(){
	std::cout << this->name << " died" << std::endl;
}

void HumanA::attack(void) const{
	std::cout << "attacks with " << this->weapon.getType() << std::endl;
}
