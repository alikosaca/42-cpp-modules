#include "print.hpp"

print::print(){}
print::~print(){}

std::string print::shorten(const std::string& value)
{
	if (value.size() > 5)
		return value.substr(0, 5) + "...";
	return value;
}

void print::printS(const std::string& value, const std::string& color){
	std::cout << color << value << color::resetColor;
}

void print::printSLn(const std::string& value, const std::string& color){
	std::cout << color << value << color::resetColor << std::endl;
}

void print::printI(const int& value, const std::string& color){
	std::cout << color << value << color::resetColor;
}

void printILn(const int& value, const std::string& color){
	std::cout << color << value << color::resetColor << std::endl;
}
