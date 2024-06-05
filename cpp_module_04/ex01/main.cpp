#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
int	main () {
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;

	const Animal *tab[4];

	for (int i = 0; i < 2; i++)
		tab[i] = new Dog();
	for (int i = 2; i < 4; i++)
		tab[i] = new Cat();
	
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete tab[i];
	
	return 0;
}