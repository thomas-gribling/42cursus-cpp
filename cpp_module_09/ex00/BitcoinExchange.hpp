#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const &src );
		~BitcoinExchange();

		BitcoinExchange &operator=( BitcoinExchange const &src );
	
	public:
		static int TreatFile( std::ifstream &f );

		class BadArgumentsException : public std::exception {
			virtual const char* what() const throw();
		};

		class FileOpenException : public std::exception {
			virtual const char* what() const throw();
		};
};