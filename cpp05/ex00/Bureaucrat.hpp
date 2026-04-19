#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Burecaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Burecaucrat();
        Burecaucrat(const std::string name, int grade);
        Burecaucrat(const Burecaucrat& other);
        Burecaucrat& operator=(const Burecaucrat& other);
        ~Burecaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
};

#endif