#include "Intern.hpp"

#include <string>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (Intern::*FormCreate)(const std::string&) const;

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}


AForm* Intern::createShrubberyCreationForm(const std::string& target) const{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formTable[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreate formCreators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

	int i = 0;
	while (i < 3 && formName != formTable[i]){
		i++;
	}
	if (i < 3 && formName == formTable[i]){
		std::cout << "Intern creates " << formName << std::endl;
        return (this->*formCreators[i])(target);
	} else{
		throw "Ups! This is not the name of the form that the intern can sign. Form Name: " + formName;
	}
}
