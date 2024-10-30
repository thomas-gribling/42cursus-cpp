#include "RPN.hpp"

// CONSTRUCTORS - DESTRUCTORS
RPN::RPN() {}

RPN::RPN( RPN const &src ) {
	(void)src;
}

RPN::~RPN() {}


// OPERATORS
RPN &RPN::operator=( RPN const &src ) {
	(void)src;
	return *this;
}


// UTILS
static int isoperator( int c ) {
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return 1;
	return 0;
}


// PROGRAM
void RPN::checkInput( std::string &exp ) {
	std::string last = "FN";

	for (size_t i = 0; i < exp.size(); i++) {
		if (!isdigit(exp[i]) && !isoperator(exp[i]) && exp[i] != ' ')
			throw std::exception();
		if (i == 0 && !isdigit(exp[i]))
			throw std::exception();
		if (i == 1 && exp[i] != ' ')
			throw std::exception();
		
		if (i > 0 && i < exp.size() - 1) {
			if ((isdigit(exp[i]) || isoperator(exp[i])) && (exp[i - 1] != ' ' || exp[i + 1] != ' '))
				throw std::exception();
		}

		if (i > 0 && isdigit(exp[i])) {
			if (last == "OP")
				last = "FN";
			else if (last == "FN")
				last = "SN";
			else if (last == "SN")
				throw std::exception();
		}
	}
}

void RPN::calc( std::string &exp ) {
	std::stack<int> s;

	for (size_t i = 0; i < exp.size(); i++) {
		if (i == 0)
			s.push(exp[i] - '0');
	}
}


// EXCEPTIONS
const char* RPN::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./RPN <expression>";
}