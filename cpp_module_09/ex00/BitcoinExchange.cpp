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


// UTILS
static int is_sdigitf( std::string &s ) {
	int count = 0;

	for (size_t i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			if (s[i] == '.' && i && i != s.size() - 1 && !count)
				count++;
			else
				return 0;
		}
	}
	return 1;
}


// PROGRAM
int BitcoinExchange::treatFile( std::ifstream &db, std::ifstream &in ) {
	std::map<std::string, float> database;
	std::string line;

	// Fill Database
	while (getline(db, line)) {
		size_t i = line.find(',');
		if (i != std::string::npos) {
			std::string val = line.substr(i + 1, line.size() - i - 1);
			if (is_sdigitf(val))
				database[line.substr(0, i)] = std::atof(val.c_str());
		}
	}

	// Read file and write outputs
	while (getline(in, line)) {
		size_t i = line.find('|');
		if (i != std::string::npos) {
			std::string date = line.substr(0, i - 1);
			std::string val = line.substr(i + 2, line.size() - i - 2);
			printLine(database, date, val);
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}

	return 0;
}

int BitcoinExchange::isDateInDB( std::map<std::string, float> &database, std::string &date ) {
	for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++) {
		if (date == it->first)
			return 1;
	}
	return 0;
}

std::string BitcoinExchange::getDate( std::map<std::string, float> &database, std::string &date ) {
	if (isDateInDB(database, date))
		return date;
	
	size_t i = date.find('-');
	std::string tmp = date.substr(0, i);
	int y = std::atoi(tmp.c_str());
	tmp = date.substr(i + 1, 2);
	int m = std::atoi(tmp.c_str());
	tmp = date.substr(i + 4, 2);
	int d = std::atoi(tmp.c_str());

	std::string out = date;
	for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++) {
		i = it->first.find('-');
		tmp = it->first.substr(0, i);
		int ty = std::atoi(tmp.c_str());
		tmp = it->first.substr(i + 1, 2);
		int tm = std::atoi(tmp.c_str());
		tmp = it->first.substr(i + 4, 2);
		int td = std::atoi(tmp.c_str());

		if (ty < y)
			out = it->first;
		if (ty == y && tm < m)
			out = it->first;
		if (ty == y && tm == m && td < d)
			out = it->first;
	}
	return out;
}

void BitcoinExchange::printLine( std::map<std::string, float> &database, std::string &date, std::string &val ) {
	/* ERRORS TO MANAGE:
	- not a number
	- not a positive number
	- not in int bounds
	*/
	if (is_sdigitf(val)) {
		float tmp = std::atof(val.c_str());
		if (tmp > 1000.0f)
			std::cout << "Error: too large number." << std::endl;
		else
			std::cout << date << " => " << val << " = " << tmp * database[getDate(database, date)] << std::endl;
	}
	else
		std::cout << "TODO ERROR" << std::endl;
}


// EXCEPTIONS
const char* BitcoinExchange::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./btc <input_file>";
}

const char* BitcoinExchange::FileDBOpenException::what() const throw() {
	return "Unable to open \"data.csv\" file!";
}
const char* BitcoinExchange::FileOpenException::what() const throw() {
	return "Unable to open input file!";
}