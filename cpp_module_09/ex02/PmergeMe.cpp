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
				throw NANException();
		}
		_v.push_back(std::atoi(av[i]));
		_l.push_back(std::atoi(av[i]));
	}
	_len = ac - 1;
}

bool PmergeMe::isSorted() {
	std::vector<int>::iterator it = _v.begin();
	int last = *it;
	for (it = ++it; it != _v.end(); it++) {
		if (*it < last)
			return false;
		last = *it;
	}
	return true;
}

void PmergeMe::printVector() {
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	clock_t start = clock();

	clock_t end = clock();
	_vTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 / 2;
}

void PmergeMe::sortList() {}

void PmergeMe::displayTimestamps() {
	std::cout << "Time to process a range of " << _len << " elements with std::vector : " << _vTime / 100 << " ms" << std::endl;
	std::cout << "Time to process a range of " << _len << " elements with std::list   : " << _lTime / 100 << " ms" << std::endl;
}


// EXCEPTIONS
const char* PmergeMe::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./PmergeMe <n1> <n2> <n3>...";
}
const char* PmergeMe::NANException::what() const throw() {
	return "Not a number!";
}

const char* PmergeMe::AlreadySortedException::what() const throw() {
	return "Your numbers are already sorted!";
}