#include "PmergeMe.hpp"

int main( int ac, char **av ) {
	// Check arguments
	try {
		if (ac < 2)
			throw PmergeMe::BadArgumentsException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (ac < 2)
		return 1;
	(void)av;
	return 0;
}