#include "RobotomyRequestForm.hpp"

#include <fstream>


RobotomyRequestForm::RobotomyRequestForm() : _target("RobotomyRequestForm"), AForm("RobotomyRequestForm", false, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : _target(target), AForm("RobotomyRequestForm", false, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : _target("RobotomyRequestForm"), AForm(other){}

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
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}