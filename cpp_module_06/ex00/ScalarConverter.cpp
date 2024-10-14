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


void ScalarConverter::fromChar( std::string const &input ) {
	char c = input[0];
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		c = input[1];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromInt( std::string const &input ) {
	(void)input;
}

void ScalarConverter::fromFloat( std::string const &input ) {
	(void)input;
}

void ScalarConverter::fromDouble( std::string const &input ) {
	(void)input;
}


void ScalarConverter::convert( std::string const &input ) {
	fromChar(input);
}