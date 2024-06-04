#include <iostream>

int	main() {
	std::string	stringVAL = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAL;
	std::string	&stringREF = stringVAL;

	std::cout << "Adress of VAL: " << &stringVAL << std::endl;
	std::cout << "Adress of PTR: " << stringPTR << std::endl;
	std::cout << "Adress of REF: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Value of VAL: " << stringVAL << std::endl;
	std::cout << "Value of PTR: " << *stringPTR << std::endl;
	std::cout << "Value of REF: " << stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Changing value" << std::endl;
	stringVAL = "I'm a vegan zombie, I only eat hairs.";

	std::cout << std::endl;
	std::cout << "Adress of VAL: " << &stringVAL << std::endl;
	std::cout << "Adress of PTR: " << stringPTR << std::endl;
	std::cout << "Adress of REF: " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Value of VAL: " << stringVAL << std::endl;
	std::cout << "Value of PTR: " << *stringPTR << std::endl;
	std::cout << "Value of REF: " << stringREF << std::endl;
	return 0;
}