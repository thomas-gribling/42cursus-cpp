#include "PmergeMe.hpp"

int main( int ac, char **av ) {
	std::cout << std::endl;
	// Check arguments
	try {
		if (ac < 2)
			throw PmergeMe::BadArgumentsException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (ac < 2) {
		std::cout << std::endl;
		return 1;
	}
	
	// push_swap 2
	try {
		PmergeMe merger;

		merger.fillContainers(ac, av);
		if (merger.isSorted())
			throw PmergeMe::AlreadySortedException();

		std::cout << "Before : ";
		merger.printVector();

		merger.sort();
		if (!merger.isSorted())
			throw PmergeMe::NotSortedException();

		std::cout << "After  : ";
		merger.printVector();
		std::cout << std::endl;
		merger.displayTimestamps();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}