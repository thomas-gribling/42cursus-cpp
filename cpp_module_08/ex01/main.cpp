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

	std::cout << std::endl << "=== TESTING ===" << std::endl;
	try {
		Span s(4);
		s.addNumber(1);
		s.addNumber(65);
		s.addNumber(10000000);
		s.addNumber(64);
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== 100K INTS TESTING ===" << std::endl;
	try {
		int len = 100000;
		Span s(len);
		for (int i = 0; i < len; i++)
			s.addNumber(i * 10);
		std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << s.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}