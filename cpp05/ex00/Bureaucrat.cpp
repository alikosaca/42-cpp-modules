#include "Bureaucrat.hpp"

Burecaucrat::Burecaucrat() : _name("anonymous"), _grade(150){}


Burecaucrat::Burecaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1){
        throw Burecaucrat::GradeTooLowException();
    }
    else if (grade > 150){
        throw Burecaucrat::GradeTooHighException();
    }
}

Burecaucrat::Burecaucrat(const Burecaucrat& other) : _name(other._name), _grade(other._grade){}

Burecaucrat& Burecaucrat::operator=(const Burecaucrat& other){
    if (this != &other){
        this->_grade = other._grade;
    }
    return *this;
}

Burecaucrat::~Burecaucrat(){}

std::string Burecaucrat::getName() const{ return(this->_name); };

int Burecaucrat::getGrade() const{ return(this->_grade); }

void Burecaucrat::incrementGrade(){
    if (this->_grade == 1){
        Burecaucrat::GradeTooHighException();
    }
    else{
        this->_grade--;
    }
}

void Burecaucrat::decrementGrade(){
    if (this->_grade == 150){
        Burecaucrat::GradeTooLowException();
    }
    else{
        this->_grade++;
    }
}

const char* Burecaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too hight. it should be in (1-150)";
}

const char* Burecaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low. it should be in (1-150)";
}


std::ostream& operator<<(std::ostream &os, const Burecaucrat &br){
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
    return os;
}