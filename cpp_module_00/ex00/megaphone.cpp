#include <iostream>

int	main(int ac, char **av) {
	std::string	curr;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < ac; i++) {
			curr.assign(av[i]);
			for (int j = 0; (size_t)j < curr.length(); j++)
				std::cout << (char)toupper(curr[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}