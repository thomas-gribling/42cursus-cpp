#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <limits>

class PmergeMe {
	private:
		std::vector<int> _v;
		std::deque<int> _d;
		double _vTime;
		double _dTime;
		size_t _len;

	public:
		PmergeMe();
		PmergeMe( PmergeMe const &src );
		~PmergeMe();

		PmergeMe &operator=( PmergeMe const &src );

		void fillContainers( int ac, char **av );
		bool isSorted();
		void printVector();
		void displayTimestamps();

		void sort();
		void sortVector( int begin, int end );
		void mergeVector( int begin, int middle, int end );
		void insertVector( int begin, int end );
		void sortDeque( int begin, int end );
		void mergeDeque( int begin, int middle, int end );
		void insertDeque( int begin, int end );

		class BadArgumentsException : public std::exception {
			virtual const char *what() const throw();
		};
		class NANException : public std::exception {
			virtual const char *what() const throw();
		};
		class IntException : public std::exception {
			virtual const char *what() const throw();
		};

		class AlreadySortedException : public std::exception {
			virtual const char *what() const throw();
		};
		class NotSortedException : public std::exception {
			virtual const char *what() const throw();
		};
};