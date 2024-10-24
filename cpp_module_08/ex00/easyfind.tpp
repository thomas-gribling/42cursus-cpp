#pragma once

#include "easyfind.hpp"

template <typename T>
void easyfind( T &t, int toFind ) {
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), toFind);
	if (it == t.end())
		throw NoOccurenceFoundException();
	std::cout << *it << " has been found!" << std::endl;
}