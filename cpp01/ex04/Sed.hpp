#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
class Sed{
	private:
		std::string fileName;
		std::string s1;
		std::string s2;
	public:
		Sed(const std::string& fileName, const std::string s1, const std::string s2);
		~Sed();
	
		void Replace();
};

#endif