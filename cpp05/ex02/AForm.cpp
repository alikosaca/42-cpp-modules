#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("confidential form"), _isSigned(false), _gradeSign(150), _gradeExecute(150){}

AForm::AForm(std::string name, bool isSigned, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(isSigned), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
    if (gradeSign < 1 || gradeExecute < 1){
        throw AForm::GradeTooHighException();
    }
    else if (gradeSign > 150 || gradeExecute > 150){
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){}

AForm& AForm::operator=(const AForm& other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm(){}

std::string AForm::getName() const{ return this->_name; }

bool AForm::getIsSigned() const{ return this->_isSigned; }

int AForm::getGradeSign() const{ return _gradeSign; }

int AForm::getGradeExecute() const{ return _gradeExecute; }

void AForm::beSigned(const Bureaucrat &b){
    if (b.getGrade() > _gradeSign){
        throw AForm::GradeTooLowException();
    }
    else{
        this->_isSigned = true;
    }
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "grade to hight, unauthorized access!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "grade To low, unauthorized access!";
}

std::ostream& operator<<(std::ostream &os, const AForm &f){
    os << "| ------------------>" << std::endl;
    os << "| Form Name:        " << f.getName() << std::endl;
    os << "| Is Signed:        " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
    os << "| Grade to sign:    " << f.getGradeSign() << std::endl;
    os << "| Grade to execute: " << f.getGradeExecute() << std::endl;
    os << "| ------------------>" << std::endl;
    return os;
}