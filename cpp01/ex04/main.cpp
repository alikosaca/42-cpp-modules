#include "Sed.hpp"

int main(int ac, char **av){
	if (ac != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	Sed rep = Sed(av[1], av[2], av[3]);
	rep.Replace();
	return 0;
}