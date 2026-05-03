#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
    private:
        AForm* createShrubberyCreationForm(const std::string& target) const;
        AForm* createRobotomyRequestForm(const std::string& target) const;
        AForm* createPresidentialPardonForm(const std::string& target) const;
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target) const;
        class FormNotFoundException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

#endif
