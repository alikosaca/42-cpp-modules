#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
	std::cout << _name + " : AwaaaakennzzzZ..." << std::endl;
}

Zombie::~Zombie(){
	std::cout << _name + " : DeeeestrooooyyyzzzZ..." << std::endl;
}

void Zombie::announce(){
	std::cout << _name + " : BraiiiiiiinnnzzzZ..." << std::endl;
}