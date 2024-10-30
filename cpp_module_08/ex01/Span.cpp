#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span( int N ) : _N(N) {}

Span::Span( Span const &src ) : _N(src._N), _v(src._v) {}

Span::~Span() {}


Span &Span::operator=( Span const &src ) {
	if (this != &src) {
		_N = src._N;
		_v = src._v;
	}
	return (*this);
}


void Span::addNumber( int n ) {
	if (_v.size() == _N)
		throw FullException();
	_v.push_back(n);
}

int Span::shortestSpan() {
	if (_v.size() <= 1)
		throw NotEnoughException();
	
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = *(std::max_element(tmp.begin(), tmp.end()));
	std::vector<int>::iterator prev = tmp.begin();
	for (std::vector<int>::iterator curr = ++tmp.begin(); curr != tmp.end(); curr++) {
		min = std::min(min, *curr - *prev);
		prev = curr;
	}
	return min;
}

int Span::longestSpan() {
	if (_v.size() <= 1)
		throw NotEnoughException();
	
	return *(std::max_element(_v.begin(), _v.end())) - *(std::min_element(_v.begin(), _v.end()));
}


const char *Span::FullException::what() const throw() {
	return "Array is full!";
}

const char *Span::NotEnoughException::what() const throw() {
	return "Array is not filled enough to calculate span! (it needs at least 2 elements)";
}