#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	Karen;
	std::string	level;

	if (ac == 1)
		std::cerr << "So I can't even express myself? This is unacceptable! We live in a DICTATORSHIP!" << std::endl;
	if (ac > 2)
		std::cerr << "Are you implying that I want to talk THAT MUCH? This is absolutely unacceptable!" << std::endl;
	if (ac != 2)
		return 1;
	level.assign(av[1]);
	Karen.complainMore(level);
	return 0;
}