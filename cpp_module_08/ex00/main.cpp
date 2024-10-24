#include "easyfind.hpp"

const char *NoOccurenceFoundException::what() const throw() {
	return "No occurences were found for this value !";
}

int main() {
	std::vector<int> v;
	v.push_back(0);
	v.push_back(20);
	v.push_back(19);

	std::cout << std::endl;
	try {
		easyfind(v, 0);
		easyfind(v, 19);
		easyfind(v, 20);
		easyfind(v, 42);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}