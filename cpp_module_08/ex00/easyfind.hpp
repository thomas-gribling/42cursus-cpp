#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class NoOccurenceFoundException : public std::exception {
	virtual const char *what() const throw();
};

template <typename T>
void easyfind( T &t, int toFind );

#include "easyfind.tpp"