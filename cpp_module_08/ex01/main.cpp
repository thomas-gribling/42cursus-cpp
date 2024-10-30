#include "Span.hpp"

int main() {

	std::cout << std::endl << "=== MAX SIZE ===" << std::endl;
	try {
		Span s(2);
		s.addNumber(1);
		std::cout << "Added an int" << std::endl;
		s.addNumber(1);
		std::cout << "Added an int" << std::endl;
		s.addNumber(1);
		std::cout << "Added an int" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== UNABLE TO CALCULATE SPANS ===" << std::endl;
	try {
		Span s(5);
		std::cout << s.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Span s(5);
		s.addNumber(1);
		std::cout << s.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Span s(5);
		std::cout << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		Span s(5);
		s.addNumber(1);
		std::cout << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== SUBJECT TESTS ===" << std::endl;
	try {
		Span s = Span(5);

		s.addNumber(6);
		s.addNumber(3);
		s.addNumber(17);
		s.addNumber(9);
		s.addNumber(11);

		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== 100K INTS TESTING ===" << std::endl;
	try {
		int len = 100000;
		std::vector<int> v;
		for (int i = 0; i < len; i++)
			v.push_back(i * 10);

		Span s(len);
		s.addNumber(v.begin(), v.end());
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}