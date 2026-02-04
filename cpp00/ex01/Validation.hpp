#ifndef VALIDATION_HPP
# define VALIDATION_HPP


#include <iostream>
#include <string>
#include <cctype>
#include "Print.hpp"
#include "Color.hpp"

class Validation{
	public:
		Validation();
		~Validation();

		static int isValidString(const std::string& value);
		static int isNumeric(const std::string& value);
		static int validString(const std::string& query, std::string& value);
		static int validNumeric(const std::string& query, std::string& value);
};

#endif