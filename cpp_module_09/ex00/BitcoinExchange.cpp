#include "BitcoinExchange.hpp"

// CONSTRUCTORS - DESTRUCTORS
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &src ) {
	(void)src;
}

BitcoinExchange::~BitcoinExchange() {}


// OPERATORS
BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &src ) {
	if (this != &src) {}
	return *this;
}


// PROGRAM
int TreatFile( std::ifstream &f ) {
	std::map<std::string, int> values;
}


// EXCEPTIONS
const char* BitcoinExchange::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./btc <input_file>";
}

const char* BitcoinExchange::FileOpenException::what() const throw() {
	return "Unable to open input file!";
}