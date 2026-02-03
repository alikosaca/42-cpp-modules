#include "Validation.hpp"

Validation::Validation(){}
Validation::~Validation(){}

int Validation::isValidString(const std::string& value){
	if(value.empty())
	{
		Print::printSLn("It cannot be empty!", Color::Red());
		return 1;
	}
	for(size_t i = 0; i < value.length(); i++)
	{
		if(!std::isprint(value[i]))
		{
			Print::printSLn("It should be printable ascii value", Color::Red());
			return 1;
		}
	}
	return 0;
}

int Validation::isNumeric(const std::string& value){
	if(value.empty())
	{
		Print::printSLn("It cannot be empty!", Color::Red());
		return 1;
	}
	for(size_t i = 0; i < value.length(); i++)
	{
		if (!std::isdigit(value[i]))
		{
			Print::printSLn("It should be a numerical value", Color::Red());
			return 1;
		}
	}
	return 0;
}


void Validation::validString(const std::string& query, std::string& value){
	while (true)
	{
		Print::printS(query, Color::Gray());
		std::getline(std::cin, value);
		if (std::cin.eof())
			break;
		if (!isValidString(value))
			break;
	}
}

void Validation::validNumeric(const std::string& query, std::string& value){
	while (true)
	{
		Print::printS(query, Color::Gray());
		std::getline(std::cin, value);
		if (std::cin.eof())
			break;
		if (!isNumeric(value))
			break;
	}
}


