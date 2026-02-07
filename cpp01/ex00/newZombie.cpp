#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *_zombie = new Zombie(name);
	if (!_zombie)
		return (NULL);
	return (_zombie);
}