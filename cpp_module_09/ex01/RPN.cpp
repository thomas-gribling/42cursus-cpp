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
static bool isoperator( int c ) {
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}


// PROGRAM
void RPN::checkInput( std::string &exp ) {
	for (size_t i = 0; i < exp.size(); i++) {
		if (!isdigit(exp[i]) && !isoperator(exp[i]) && exp[i] != ' ')
			throw ExpressionException();
	}
}

void RPN::calc( std::string &exp ) {
	std::stack<int> s;
	int n1, n2, res;

	for (size_t i = 0; i < exp.size(); i++) {
		if (isdigit(exp[i]))
			s.push(exp[i] - '0');
		if (isoperator(exp[i])) {
			if (s.size() < 2)
				throw ExpressionException();
			
			n2 = s.top();
			s.pop();
			n1 = s.top();
			s.pop();
			if (exp[i] == '+')
				res = n1 + n2;
			if (exp[i] == '-')
				res = n1 - n2;
			if (exp[i] == '/')
				res = n1 / n2;
			if (exp[i] == '*')
				res = n1 * n2;
			s.push(res);
		}
	}
	if (s.size() == 1)
		std::cout << res << std::endl;
	else
		throw ExpressionException();
}


// EXCEPTIONS
const char* RPN::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./RPN <expression>";
}

const char* RPN::ExpressionException::what() const throw() {
	return "Invalid expression input!";
}