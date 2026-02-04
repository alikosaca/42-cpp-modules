#include "Print.hpp"

Print::Print(){}
Print::~Print(){}

std::string Print::shorten(const std::string& value)
{
	if (value.length() >= 10)
		return value.substr(0, 9) + ".";
	return value;
}

void Print::printS(const std::string& value, const std::string& color){
	std::cout << color << value << Color::ResetColor();
}

void Print::printSLn(const std::string& value, const std::string& color){
	std::cout << color << value << Color::ResetColor() << std::endl;
}

void Print::printI(const int& value, const std::string& color){
	std::cout << color << value << Color::ResetColor();
}

void Print::printILn(const int& value, const std::string& color){
	std::cout << color << value << Color::ResetColor() << std::endl;
}
