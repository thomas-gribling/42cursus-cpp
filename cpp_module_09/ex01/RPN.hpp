#pragma once

#include <iostream>
#include <stdexcept>
#include <stack>

class RPN {
	private:
		RPN();
		RPN( RPN const &src );
		~RPN();

		RPN &operator=( RPN const &src );
	
	public:
		static void checkInput( std::string &exp );
		static void calc( std::string &exp );

		class BadArgumentsException : public std::exception {
			virtual const char* what() const throw();
		};

		class ExpressionException : public std::exception {
			virtual const char* what() const throw();
		};
};