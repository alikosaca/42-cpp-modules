#include "Form.hpp"

Form::Form() : _name("confidential form"), _isSigned(false), _gradeSign(150), _gradeExecute(150){}

Form::Form(std::string name, bool isSigned, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(isSigned), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
    if (gradeSign < 1 || gradeExecute < 1){
        throw Form::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150){
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){}

Form& Form::operator=(const Form& other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(){}

std::string Form::getName() const{ return this->_name; }

bool Form::getIsSigned() const{ return this->_isSigned; }

int Form::getGradeSign() const{ return _gradeSign; }

int Form::getGradeExecute() const{ return _gradeExecute; }

void Form::beSigned(const Bureaucrat &b){
    if (b.getGrade() > _gradeSign){
        throw Form::GradeTooLowException();
    }
    else{
        this->_isSigned = true;
    }
}

const char* Form::GradeTooHighException::what() const throw(){
    return "grade to hight, unauthorized access!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "grade To low, unauthorized access!";
}

std::ostream& operator<<(std::ostream &os, const Form &f){
    os << "| ------------------>" << std::endl;
    os << "| Form Name:        " << f.getName() << std::endl;
    os << "| Is Signed:        " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "| Grade to sign:    " << f.getGradeSign() << std::endl;
    os << "| Grade to execute: " << f.getGradeExecute() << std::endl;
    os << "| ------------------>" << std::endl;
    return os;
}