#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T>();
		MutantStack<T>( MutantStack<T> const &src );
		~MutantStack<T>();

		MutantStack<T> &operator=( MutantStack<T> const &src );

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator cbegin();
		const_iterator cend();

		iterator rbegin();
		iterator rebd();
		const_iterator crbegin();
		const_iterator crend();
};

#include "MutantStack.tpp"