#include "FragTrap.hpp"

int main(void) {
	FragTrap frag("harry potter");
	FragTrap trap;

	std::cout << "<--- Test: 1 --->" << std::endl;
	frag.attack("bot");
	trap.takeDamage(1);
	frag.beRepaired(5);
	std::cout << "<----->" << std::endl;

	std::cout << "\n--- Test: 2---" << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "[" << i << "] ";
		frag.attack("bot");
	}
	std::cout << "<----->" << std::endl;

	std::cout << "\n--- Test: 3 ---" << std::endl;
	trap.takeDamage(10);
	trap.beRepaired(5);
	trap.attack("bot");
	std::cout << "<----->" << std::endl;
	return 0;
}