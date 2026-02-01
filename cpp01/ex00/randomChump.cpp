#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie _zombie(name);
	_zombie.announce();
}

void Zombie::announce(){
	std::cout << _name + " : BraiiiiiiinnnzzzZ..." << std::endl;
}