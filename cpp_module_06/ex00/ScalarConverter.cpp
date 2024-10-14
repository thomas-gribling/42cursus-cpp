#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
	(void)src;
}

ScalarConverter::~ScalarConverter() {}


ScalarConverter &ScalarConverter::operator=( ScalarConverter const &src ) {
	(void)src;
	return *this;
}


void ScalarConverter::convert( std::string const &input ) {
	std::cout << input << std::endl;
}