#ifndef COLOR_HPP
# define COLOR_HPP

#include <iostream>
#include <string>

class color{
	public:
	color();
	~color();

	static std::string green;
	static std::string red;
	static std::string orange;
	static std::string black;
	static std::string blue;
	static std::string resetColor;
};

#endif