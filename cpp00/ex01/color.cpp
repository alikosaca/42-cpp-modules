#include "color.hpp"

color::color(){}
color::~color(){}

// void color::green(){
// 	std::cout << "\e[32m";
// }

// void color::red(){
// 	std::cout << "\033[31m";
// }

// void color::black(){
// 	std::cout << "\033[30m";
// }

// void color::orange(){
// 	std::cout << "\033[38;5;166m";
// }

// void color::resetColor(){
// 	std::cout << "\033[0m";
// }

std::string color::green = "\e[32m";
std::string color::red = "\033[31m";
std::string color::orange = "\033[38;5;166m";
std::string color::black = "\033[30m";
std::string color::blue = "\e[36m";
std::string color::gray = "\033[90m";
std::string color::white = "\033[37m";
std::string color::resetColor = "\033[0m";
