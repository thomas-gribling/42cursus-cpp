#include "PmergeMe.hpp"

// CONSTRUCTORS - DESTRUCTORS
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( PmergeMe const &src ) {
	*this = src;
}

PmergeMe::~PmergeMe() {}


// OPERATORS
PmergeMe &PmergeMe::operator=( PmergeMe const &src ) {
	if (this != &src)
		*this = src;
	return *this;
}


// EXCEPTIONS
const char* PmergeMe::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./PmergeMe <n1> <n2> <n3>...";
}