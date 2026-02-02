#ifndef PRINT_HPP
# define PRINT_HPP

#include <string>
#include <iostream>
#include "color.hpp"

class print{
	public:
	print();
	~print();

	static std::string shorten(const std::string& value);
	static void printS(const std::string& value, const std::string& color);
	static void printSLn(const std::string& value, const std::string& color);
	static void printI(const int& value, const std::string& color);
	static void printILn(const int& value, const std::string& color);
};

#endif