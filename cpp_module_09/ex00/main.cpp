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

	// Open files
	std::ifstream	db;
	std::ifstream	in;
	db.open("data.csv");
	in.open(av[1]);
	try {
		if (!db.good())
			throw BitcoinExchange::FileDBOpenException();
		if (!in.good())
			throw BitcoinExchange::FileOpenException();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	BitcoinExchange::treatFile(db, in);

	db.close();
	in.close();
	return 0;
}