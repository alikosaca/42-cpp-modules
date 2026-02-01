#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::~Zombie(){}

void Zombie::setName(const std::string& name){
	this->_name = name;
}

Zombie* zombieHorde(int N, const std::string& name)
{
    if (N <= 0) return nullptr;
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setName(name); // veya uygun constructor kullanın
    return horde;
}

