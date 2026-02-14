#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "<--- Test 1 --->" << std::endl;
	const int size = 10;
	Animal* animals[size];
	for (int i = 0; i < size; i++) {
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- DELETING ANIMALS ---" << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i]; // Bu satır hem Dog/Cat hem de Brain yıkıcılarını çağırmalı!
	}

	std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
	Dog medor;
	Dog copy_medor = medor; // Copy constructor çalışır
	std::cout << "<--- --->" << std::endl;

	return 0;
}