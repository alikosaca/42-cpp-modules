#include "Sed.hpp"

int main(int ac, char **av){
	if (ac != 4)
		std::cout << "sıkıntı kardeşim" << std::endl;

	Sed rep = Sed(av[1], av[2], av[3]);
	rep.Replace();
	return 0;
}