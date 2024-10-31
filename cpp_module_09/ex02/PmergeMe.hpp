#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe {
	private:
		std::vector<int> _v;
		std::list<int> _l;
		double _vTime;
		double _lTime;
		size_t _len;

	public:
		PmergeMe();
		PmergeMe( PmergeMe const &src );
		~PmergeMe();

		PmergeMe &operator=( PmergeMe const &src );

		void fillContainers( int ac, char **av );
		void printVector();
		void sortVector();
		void sortList();
		void displayTimestamps();

		class BadArgumentsException : public std::exception {
			virtual const char *what() const throw();
		};
		class NANException : public std::exception {
			virtual const char *what() const throw();
		};

		class AlreadySortedException : public std::exception {
			virtual const char *what() const throw();
		};
};