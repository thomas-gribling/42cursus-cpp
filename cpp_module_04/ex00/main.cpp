#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main () {
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl << "\"ANIMAL\" TESTS:" << std::endl;
	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	std::cout << std::endl << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl << "\"WRONG ANIMAL\" TESTS:" << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}