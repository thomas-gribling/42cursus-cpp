#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <cstdlib>
#include <limits>

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const &src );
		~BitcoinExchange();

		BitcoinExchange &operator=( BitcoinExchange const &src );
	
	public:
		static int treatFile( std::ifstream &db, std::ifstream &in );
		static void printLine( std::map<std::string, double> &database, std::string &date, std::string &val );

		static int isDateInDB( std::map<std::string, double> &database, std::string &date );
		static std::string getDate( std::map<std::string, double> &database, std::string &date );

		class BadArgumentsException : public std::exception {
			virtual const char* what() const throw();
		};

		class FileDBOpenException : public std::exception {
			virtual const char* what() const throw();
		};
		class FileOpenException : public std::exception {
			virtual const char* what() const throw();
		};
};