#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include "Zombie.hpp"

class Zombie{
	private:
		std::string _name;
	
	public:
		Zombie();
		~Zombie();

		void setName(const std::string& name);
		void announce(void);
};

Zombie* zombieHorder(int N, std::string name);

#endif