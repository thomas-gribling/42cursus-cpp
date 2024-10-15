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
	if (input.empty())
		return false;
	
	int start = 0;
	if (input[0] == '+' || input[0] == '-') {
		if (input.size() == 1)
			return false;
		else
			start = 1;
	}

	if (!isdigit(input[start]))
		return false;
	if (countChar(input, '.') != 1)
		return false;
	if (input[input.size() - 1] != 'f' && input[input.size() - 1] != 'F')
		return false;
	if (countChar(input, input[input.size() - 1]) != 1)
		return false;

	int dot = input.find('.');
	if (!isdigit(input[dot - 1]) || !isdigit(input[dot + 1]))
		return false;
	
	for (int i = start; i < (int)input.size() - 1; i++)
		if (i != dot && !isdigit(input[i]))
			return false;
	
	return true;
}

bool ScalarConverter::isDouble( std::string const &input ) {
	if (input.empty())
		return false;
	
	int start = 0;
	if (input[0] == '+' || input[0] == '-') {
		if (input.size() == 1)
			return false;
		else
			start = 1;
	}

	if (!isdigit(input[start]) || !isdigit(input[input.size() - 1]))
		return false;
	if (countChar(input, '.') != 1)
		return false;

	int dot = input.find('.');
	if (!isdigit(input[dot - 1]) || !isdigit(input[dot + 1]))
		return false;
	
	for (int i = start; i < (int)input.size() - 1; i++)
		if (i != dot && !isdigit(input[i]))
			return false;
	
	return true;
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

	long long tmp = std::atoll(input.c_str());
	displayChar(tmp, c);
	displayInt(tmp, i);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromFloat( std::string const &input ) {
	float f = std::atof(input.c_str());
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	long long tmp = std::atoll(input.c_str());
	displayChar(tmp, c);
	displayInt(tmp, i);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromDouble( std::string const &input ) {
	double d = std::atof(input.c_str());
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	long long tmp = std::atoll(input.c_str());
	displayChar(tmp, c);
	displayInt(tmp, i);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
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

void ScalarConverter::displayChar( long long tmp, char c ) {
	if (tmp < std::numeric_limits<char>::min() || tmp > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::displayInt( long long tmp, int i ) {
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
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

int countChar( std::string const &s, char toCount ) {
	int count = 0;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == toCount)
			count++;
	return count;
}