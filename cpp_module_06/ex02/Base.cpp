#include "Base.hpp"

Base::~Base() {}


Base * generate(void) {
	int n = std::rand() % 3;

	(void)n;
}

void identify(Base* p) {}

void identify(Base& p) {}