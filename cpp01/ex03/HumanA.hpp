#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private:
    std::string name;
    Weapon& weapon;
    public:
		HumanA(std::string name, Weapon& club);
		~HumanA();

		void attack(void) const;
		
};

#endif