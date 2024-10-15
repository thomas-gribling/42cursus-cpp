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


bool ScalarConverter::isChar( std::string const &input ) {
	if (input.empty())
		return false;
	
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;

	if (input.size() == 1 && !isdigit(input[0]))
		return true;

	return false;
}

bool ScalarConverter::isInt( std::string const &input ) {
	if (input.empty())
		return false;
	
	int start = 0;
	if (input[0] == '+' || input[0] == '-') {
		if (input.size() == 1)
			return false;
		else
			start = 1;
	}

	for (int i = start; i < (int)input.size(); i++) {
		if (!isdigit(input[i]))
			return false;
	}

	return true;
}

bool ScalarConverter::isFloat( std::string const &input ) {
	(void)input;
	return false;
}

bool ScalarConverter::isDouble( std::string const &input ) {
	(void)input;
	return false;
}

bool ScalarConverter::isSpecial( std::string const &input ) {
	std::string inputs[6] = {"-inff", "+inff", "-inf", "+inf", "nanf", "nan"};

	for (int i = 0; i < 6; i++)
		if (input == inputs[i])
			return true;
	return false;
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
	int i = std::atoi(input.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromFloat( std::string const &input ) {
	(void)input;
}

void ScalarConverter::fromDouble( std::string const &input ) {
	(void)input;
}

void ScalarConverter::fromSpecial( std::string const &input ) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nan" || input == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	if (input == "-inf" || input == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (input == "+inf" || input == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}


void ScalarConverter::convert( std::string const &input ) {
	if (isChar(input))
		fromChar(input);
	else if (isInt(input))
		fromInt(input);
	else if (isFloat(input))
		fromFloat(input);
	else if (isDouble(input))
		fromDouble(input);
	else if (isSpecial(input))
		fromSpecial(input);
	else
		std::cerr << "Error: Invalid input!" << std::endl;
}