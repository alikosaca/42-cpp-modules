#include "Zombie.hpp"

Zombie *zombieHorder(int N, std::string name)
{
	Zombie *zombieHorder = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombieHorder[i].setName(name);
	return (zombieHorder);
}