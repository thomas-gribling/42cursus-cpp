#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}


Base * generate(void) {
	int n = std::rand() % 3;

	switch (n) {
		case 0:
			return dynamic_cast<Base*>(new A);
			break;
		case 1:
			return dynamic_cast<Base*>(new B);
			break;
		case 2:
			return dynamic_cast<Base*>(new C);
			break;
	}
	return NULL;
}

void identify(Base* p) {
	A *ptr_a = dynamic_cast<A*>(p);
	B *ptr_b = dynamic_cast<B*>(p);
	C *ptr_c = dynamic_cast<C*>(p);

	if (ptr_a)
		std::cout << "A" << std::endl;
	if (ptr_b)
		std::cout << "B" << std::endl;
	if (ptr_c)
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A &ref_a = dynamic_cast<A&>(p);
		(void)ref_a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try {
		B &ref_b = dynamic_cast<B&>(p);
		(void)ref_b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try {
		C &ref_c = dynamic_cast<C&>(p);
		(void)ref_c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}