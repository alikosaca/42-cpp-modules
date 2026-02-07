#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name){
	Zombie* horde = new Zombie[n];
	if (!horde)
		return NULL;
	for(int i; i < n; i++)
		horde[i].setName(name);
	return horde;
}