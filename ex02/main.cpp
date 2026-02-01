#include "Zombie.hpp"

int main(void)
{
	Zombie *_newZombie;

	_newZombie = newZombie("new zombiee");
	_newZombie->announce();
	randomChump("random zombiee");
	delete _newZombie;
	return 0;
}