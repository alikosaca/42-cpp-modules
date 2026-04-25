#include "ShrubberyCreationForm.hpp"

#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : _target("ShrubberyCreationForm"), AForm("ShrubberyCreationForm", false, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target), AForm("ShrubberyCreationForm", false, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : _target("ShrubberyCreationForm"), AForm(other){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::action() const{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw FileNotOpenException();
    }
    else {
        file << "              v .   ._, |_  .," << std::endl;
        file << "           `-._\\/  .  \\ /    |/_" << std::endl;
        file << "               \\  \\, y | \\//" << std::endl;
        file << "         _\\_.___\\, \\/-.\\||" << std::endl;
        file << "           `7-,--.`._||  / / ," << std::endl;
        file << "           /'     `-. `./ / |/_." << std::endl;
        file << "                     |----|//" << std::endl;
        file << "                     |_    / " << std::endl;
        file << "     -|||-           |-  _|  " << std::endl;
        file << "     - | -   _       |   =|  " << std::endl;
        file << "      -|-   |-|      |    |  " << std::endl;
        file << "-------|----|-|---|-/ ,  . \\--------._" << std::endl;
    }
    file.close();
}