#include "PresidentialPardonForm.hpp"

#include <fstream>


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("PresidentialPardonForm"){}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target("PresidentialPardonForm"){}

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