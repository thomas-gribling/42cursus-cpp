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
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan() {
	if (_v.size() <= 1)
		throw NotEnoughException();
	
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}


const char *Span::FullException::what() const throw() {
	return "Array is full!";
}

const char *Span::NotEnoughException::what() const throw() {
	return "Array is not filled enough to calculate span! (it needs at least 2 elements)";
}