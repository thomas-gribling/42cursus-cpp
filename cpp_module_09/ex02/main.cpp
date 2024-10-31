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
	
	// push_swap 2
	try {
		PmergeMe merger;
		
		merger.fillContainers(ac, av);
		if (merger.isSorted())
			throw PmergeMe::AlreadySortedException();

		std::cout << "Before: ";
		merger.printVector();

		merger.sortVector();
		merger.sortList();

		std::cout << "After:  ";
		merger.printVector();
		merger.displayTimestamps();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}