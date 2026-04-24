#include "PresidentialPardonForm.hpp"

#include <fstream>


PresidentialPardonForm::PresidentialPardonForm() : _target("PresidentialPardonForm"), AForm("PresidentialPardonForm", false, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : _target(target), AForm("PresidentialPardonForm", false, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : _target("PresidentialPardonForm"), AForm(other){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action() const{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}