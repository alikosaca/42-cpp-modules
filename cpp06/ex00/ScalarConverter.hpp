#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


#include <iostream>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void Convert(const std::string &literal);

};

#endif