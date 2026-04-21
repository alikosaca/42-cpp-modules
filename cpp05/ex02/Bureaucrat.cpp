#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150){}


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    if (grade < 1){
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade > 150){
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other){
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{ return(this->_name); };

int Bureaucrat::getGrade() const{ return(this->_grade); }

void Bureaucrat::incrementGrade(){
    if (this->_grade == 1){
        throw Bureaucrat::GradeTooHighException();
    }
    else{
        this->_grade--;
    }
}

void Bureaucrat::decrementGrade(){
    if (this->_grade == 150){
        throw Bureaucrat::GradeTooLowException();
    }
    else{
        this->_grade++;
    }
}

void Bureaucrat::signForm(Form &f) const{
    try{
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch(std::exception &e){
        std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too hight. it should be in (1-150)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low. it should be in (1-150)";
}


std::ostream& operator<<(std::ostream &os, const Bureaucrat &br){
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
    return os;
}