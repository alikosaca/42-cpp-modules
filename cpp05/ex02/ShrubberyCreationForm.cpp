#include "ShrubberyCreationForm.hpp"

#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("ShrubberyCreationForm"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target("ShrubberyCreationForm"){}

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