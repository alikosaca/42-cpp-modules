#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << this->name << " was createed" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(){
	std::cout << this->name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}

