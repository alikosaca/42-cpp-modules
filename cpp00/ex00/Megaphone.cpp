#include <iostream>

int main(int ac, char *const av[])
{
	if (ac > 1)
	{
		for (int i = 1; ac > i; i++)
		{
			for(int j = 0; av[i][j] != '\0'; j++)
			{
				std::cout << static_cast<char>(std::toupper(av[i][j]));
			}
		}
		std::cout << std::endl;
	}
	else if (ac  == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}