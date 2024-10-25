#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
	private:
		T *_arr;
		unsigned int _len;

	public:
		Array();
		Array( unsigned int n );
		Array( Array const &src );
		~Array();

		int size() const;

		Array &operator=( Array const &src );
		T &operator[]( int i );

		class IndexOutOfBoundsException : public std::exception {
			virtual const char* what() const throw();
		};
};
#include "Array.tpp"