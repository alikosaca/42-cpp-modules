#include "Zombie.hpp"

int main(void){
	Zombie* _zombie = newZombie("Foo");
	_zombie->announce();
	randomChump("Bar");
	delete _zombie;
	return 0;
}
