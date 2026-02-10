#include "Zombie.hpp"

int main(void){
	int n = 22;
	Zombie* horde = zombieHorde(n, "Foo");
	for(int i = 0 ; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}