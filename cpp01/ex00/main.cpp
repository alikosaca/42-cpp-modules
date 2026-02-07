#include "Zombie.hpp"

int main(void){
	Zombie* _zombie = newZombie("Foo");
	if (!_zombie)
		return 1;
	_zombie->announce();
	randomChump("Bar");
	delete _zombie;
	return 0;
}