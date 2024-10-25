#pragma once

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack( MutantStack<T> const &src ) {
	(void)src;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
MutantStack<T> &MutantStack<T>::operator=( MutantStack<T> const &src ) {
	(void)src;
}