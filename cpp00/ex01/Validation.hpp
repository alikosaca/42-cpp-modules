#ifndef VALIDATION_HPP
# define VALIDATION_HPP


#include <iostream>
#include <string>
#include <cctype>
#include "print.hpp"
#include "color.hpp"

class Validation{
	public:
	Validation();
	~Validation();

	static void validControlNumeric(const std::string& value);
	static int isValidString(const std::string& value);
	static int isNumeric(const std::string& value);
	static void validString(const std::string& query, std::string& value);
	static void validNumeric(const std::string& query, std::string& value);
};

#endif