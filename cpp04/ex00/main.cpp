#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "<--- Test 1 --->" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	std::cout << "<--- --->" << std::endl;
	
	std::cout << "<--- Test 2 --->" << std::endl;
	const WrongAnimal* wAnimal = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();
	wAnimal->makeSound();
	wCat->makeSound();
	delete wAnimal;
	delete wCat;
	std::cout << "<--- --->" << std::endl;
	
	std::cout << "<--- Test 3 --->" << std::endl;
	const WrongCat* wCat2 = new WrongCat();
	wCat2->makeSound();
	delete wCat2;
	std::cout << "<--- --->" << std::endl;
	
	std::cout << "<--- Test 4 --->" << std::endl;
	const Cat* i2 = new Cat();
	i2->makeSound();
	delete i2;

	return 0;
}