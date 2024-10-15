#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const &src );
		~ScalarConverter();

		ScalarConverter &operator=( ScalarConverter const &src );

		static bool isChar( std::string const &input );
		static bool isInt( std::string const &input );
		static bool isFloat( std::string const &input );
		static bool isDouble( std::string const &input );
		static bool isSpecial( std::string const &input );

		static void fromChar( std::string const &input );
		static void fromInt( std::string const &input );
		static void fromFloat( std::string const &input );
		static void fromDouble( std::string const &input );
		static void fromSpecial( std::string const &input );

	public:
		static void convert( std::string const &input );
};

#endif // SCALARCONVERTER_HPP