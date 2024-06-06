#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
	Character	p1("Pedro");
	Character	p2("Pierrot");
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	MateriaSource source;

	std::cout << std::endl;

	p1.use(-1, p2); // first test inventory bounds
	p1.use(0, p2); // check that it is empty
	p1.use(1, p2);
	p1.use(2, p2);
	p1.use(3, p2);
	p1.use(4, p2);

	std::cout << std::endl;

	source.learnMateria(NULL); // test learning unexisting materia
	source.learnMateria(ice); // let's fill our source
	source.learnMateria(cure);
	source.learnMateria(cure);
	source.learnMateria(ice);
	source.learnMateria(ice);

	std::cout << std::endl;

	AMateria *anotherIce = source.createMateria("ice"); // try to recreate Materias from what the source learnt
	AMateria *anotherCure = source.createMateria("cure");
	AMateria *whoAreU = source.createMateria("fire");
	(void)whoAreU;

	std::cout << std::endl;

	p1.equip(anotherIce); // let's equip some Materias
	p1.equip(anotherCure);

	std::cout << std::endl;

	p1.use(0, p2); // test that they're correctly assigned to their slots
	p1.use(1, p2);
	p1.use(2, p2);
	p1.use(3, p2);

	std::cout << std::endl;

	p1.equip(NULL); // test an unexisting Materia
	p1.equip(anotherIce); // test the inventory limit
	p1.equip(anotherCure);
	p1.equip(ice);

	std::cout << std::endl;

	p1.use(0, p2); // test the full inventory
	p1.use(1, p2);
	p1.use(2, p2);
	p1.use(3, p2);

	std::cout << std::endl;

	p1.unequip(-1); // test bounds again
	p1.unequip(0); // test removing Materias from specific slots
	p1.unequip(3);
	p1.unequip(3); // test removing a Materia from an empty slot
	p1.unequip(4);

	std::cout << std::endl;

	p1.use(0, p2); // test that it worked
	p1.use(1, p2);
	p1.use(2, p2);
	p1.use(3, p2);

	std::cout << std::endl;

	delete ice; // Character will automatically delete equiped Materias
	delete cure;
	return 0;
}