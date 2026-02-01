#include "Zombie.hpp"

Zombie *newZombie(std::string name){
	Zombie *_zombie = new Zombie(name);
	return (_zombie);
}