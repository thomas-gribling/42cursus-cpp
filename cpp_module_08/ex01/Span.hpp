#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span {
	private:
		unsigned _N;
		std::vector<int> _v;

	public:
		Span();
		Span( int N );
		Span( Span const &src );
		~Span();

		Span &operator=( Span const &src );

		void addNumber( int n );
		int shortestSpan();
		int longestSpan();

		template <typename I>
		void addNumber( I begin, I end ) {
			while (begin != end) {
				addNumber(*begin);
				begin++;
			}
		}

		class FullException : public std::exception {
			virtual const char *what() const throw();
		};

		class NotEnoughException : public std::exception {
			virtual const char *what() const throw();
		};
};