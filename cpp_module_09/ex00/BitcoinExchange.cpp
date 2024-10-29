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

static int countChar( std::string const &s, char toCount ) {
	int count = 0;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == toCount)
			count++;
	return count;
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
	int n = 0;
	while (getline(in, line)) {
		int valid = 0;

		size_t i = line.find('|');
		std::string date;
		std::string val;
		if (i != std::string::npos && i != line.size() - 1) {
			date = line.substr(0, i - 1);
			val = line.substr(i + 2, line.size() - i - 2);
			valid = 1;
		}

		if (i == 0 || i == line.size() - 1 || line[i - 1] != ' ' || line[i + 1] != ' ')
			valid = 0;
		if (i == 1 || i == line.size() - 2 || line[i - 2] == ' ' || line[i + 2] == ' ')
			valid = 0;

		if (valid) {
			if (date.size() != 10)
				valid = 0;
			if (countChar(date, '-') != 2)
				valid = 0;
			if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]))
				valid = 0;
			if (!isdigit(date[5]) || !isdigit(date[6]) || !isdigit(date[8]) || !isdigit(date[9]))
				valid = 0;
			if (date[4] != '-' || date[7] != '-')
				valid = 0;
		}

		if (((!n && isdigit(line[0])) || n) && !line.empty()) {
			if (valid)
				printLine(database, date, val);
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
		if (line.empty())
			std::cout << std::endl;
		n++;
	}

	return 0;
}

void BitcoinExchange::printLine( std::map<std::string, float> &database, std::string &date, std::string &val ) {
	int error = 0;

	std::string tmp = val.substr(1, val.size() - 1);
	if (!is_sdigitf(val) && is_sdigitf(tmp) && val[0] == '-')
		error = 1;
	if (!is_sdigitf(val) && is_sdigitf(tmp) && val[0] != '+' && val[0] != '-')
		error = 2;

	float valf = std::atof(val.c_str());
	if (valf > 1000.0f)
		error = 3;
	
	if (getDate(database, date) == "NA")
		error = 4;

	switch (error) {
		case 0:
			std::cout << date << " => " << val << " = " << valf * database[getDate(database, date)] << std::endl;
			break;
		case 1:
			std::cout << "negative" << std::endl;
			break;
		case 2:
			std::cout << "not a number" << std::endl;
			break;
		case 3:
			std::cout << "Error: too large number." << std::endl;
			break;
		default:
			std::cout << "unknown" << std::endl;
	}
}

std::string BitcoinExchange::getDate( std::map<std::string, float> &database, std::string &date ) {
	size_t i = date.find('-');
	std::string tmp = date.substr(0, i);
	int y = std::atoi(tmp.c_str());
	tmp = date.substr(i + 1, 2);
	int m = std::atoi(tmp.c_str());
	tmp = date.substr(i + 4, 2);
	int d = std::atoi(tmp.c_str());

	std::string out = "NA";
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
		if (ty == y && tm == m && td == d)
			out = it->first;
	}
	return out;
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