#include "Color.hpp"

Color::Color(){}
Color::~Color(){}

const std::string Color::Green()
{
	return "\e[32m";
}

const std::string Color::Red(){
	return "\033[31m";
}

const std::string Color::Orange(){
	return "\033[38;5;166m";
}

const std::string Color::Blue(){
	return "\e[36m";
}

const std::string Color::Gray(){
	return "\033[90m";
}

const std::string Color::White(){
	return "\033[37m";
}

const std::string Color::ResetColor(){
	return "\033[0m";
}