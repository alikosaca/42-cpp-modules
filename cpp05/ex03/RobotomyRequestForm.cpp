#include "RobotomyRequestForm.hpp"

#include <fstream>
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("RobotomyRequestForm"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target("RobotomyRequestForm"){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::action() const{
    std::cout << "BIIZZZ... VIIIRRR... DIIIRR... *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}