#pragma once

#include <iostream>
#include <stdexcept>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe( PmergeMe const &src );
		~PmergeMe();

		PmergeMe &operator=( PmergeMe const &src );

	public:
		class BadArgumentsException : public std::exception {
			virtual const char *what() const throw();
		};
};