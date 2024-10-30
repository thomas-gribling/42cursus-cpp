#include "PmergeMe.hpp"

// CONSTRUCTORS - DESTRUCTORS
PmergeMe::PmergeMe() {
	_vTime = 0;
	_lTime = 0;
	_len = 0;
}

PmergeMe::PmergeMe( PmergeMe const &src ) {
	*this = src;
}

PmergeMe::~PmergeMe() {}


// OPERATORS
PmergeMe &PmergeMe::operator=( PmergeMe const &src ) {
	if (this != &src) {
		_v = src._v;
		_l = src._l;
		_vTime = src._vTime;
		_lTime = src._lTime;
		_len = src._len;
	}
	return *this;
}


// PROGRAM
void PmergeMe::fillContainers( int ac, char **av ) {
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]))
				throw std::exception();
		}
		_v.push_back(std::atoi(av[i]));
		_l.push_back(std::atoi(av[i]));
	}
	_len = ac - 1;
}

void PmergeMe::printVector() {
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::sortVector() {}

void PmergeMe::sortList() {}

void PmergeMe::displayTimestamps() {
	std::cout << "Time to process a range of " << _len << " elements with std::vector : " << _vTime / 1000 << " s" << std::endl;
	std::cout << "Time to process a range of " << _len << " elements with std::list   : " << _lTime / 1000 << " s" << std::endl;
}


// EXCEPTIONS
const char* PmergeMe::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./PmergeMe <n1> <n2> <n3>...";
}