#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac < 2)
		std::cerr << "Please enter an argument!" << std::endl;
	if (ac > 2)
		std::cerr << "Please enter only one argument!" << std::endl;
	if (ac != 2)
		std::cerr << "Usage: ./convert <to_convert>" << std::endl;
	else {
		std::string curr;
		curr.assign(av[1]);
		ScalarConverter::convert(curr);
	}
	return ac != 2;
}