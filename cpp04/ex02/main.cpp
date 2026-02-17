#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

	std::cout << "--- 1. Temel Nesne Olusturma ---" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl << "--- 2. Ses Testi ---" << std::endl;
	j->makeSound();
	i->makeSound();

	std::cout << std::endl << "--- 3. Bellek Temizligi (Leak Kontrolu) ---" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "--- 4. Dizi Testi (Ex01 gereksinimi) ---" << std::endl;
	const AAnimal* animals[4];
	for (int k = 0; k < 2; k++) animals[k] = new Dog();
	for (int k = 2; k < 4; k++) animals[k] = new Cat();

    for (int k = 0; k < 4; k++) delete animals[k];

	std::cout << std::endl << "--- 5. Deep Copy Testi ---" << std::endl;
	Dog basic;
	{
	    Dog tmp = basic;
	}

    return 0;
}