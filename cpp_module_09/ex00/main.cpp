#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	// Check arguments
	try {
		if (ac != 2)
			throw BitcoinExchange::BadArgumentsException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	if (ac != 2)
		return 1;
	(void)av;

	// Open file
	std::ifstream	f;
	f.open(av[1]);
	try {
		if (f.good() == false)
			throw BitcoinExchange::FileOpenException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	f.close();
	return 0;
}