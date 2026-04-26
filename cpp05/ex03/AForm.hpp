#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExecute;
    public:
        AForm();
        AForm(std::string name, bool isSigned, const int gradeSign, const int _gradeExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

        void beSigned(const Bureaucrat &b);

        void execute(Bureaucrat const &executor) const;
        virtual void action() const = 0;

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
        class SigningTheSameFormException : public std::exception{
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            virtual const char* what() const throw();
        };
        class FileNotOpenException : public std::exception {
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif