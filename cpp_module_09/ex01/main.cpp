#include "RPN.hpp"

int main( int ac, char **av ) {
	// Check arguments
	try {
		if (ac != 2)
			throw RPN::BadArgumentsException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (ac != 2)
		return 1;
	
	// Treat expression
	std::string exp;
	exp.assign(av[1]);
	try {
		RPN::checkInput(exp);
		RPN::calc(exp);
	}
	catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}