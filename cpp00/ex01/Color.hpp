#ifndef COLOR_HPP
# define COLOR_HPP

#include <string>

class Color
{
	public:
		Color();
		~Color();
		static const std::string Green();
		static const std::string Red();
		static const std::string Orange();
		static const std::string Blue();
		static const std::string Gray();
		static const std::string White();
		static const std::string ResetColor();
};

#endif