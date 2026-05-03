#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

#include <ctime>


int main(void)
{
    std::srand(std::time(NULL));
    AForm* form = NULL;
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 1 | ->" << std::endl;
        Intern ali;
        Bureaucrat ibrahim("Boss", 1);
        form = ali.makeForm("shrubbery creation", "razer");
        std::cout << ibrahim << std::endl;
        std::cout << *form << std::endl;

        ibrahim.signForm(*form);
        ibrahim.executeForm(*form);
        delete form;
        form = NULL;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
        delete form;
        form = NULL;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 2 | ->" << std::endl;
        Intern ali;
        Bureaucrat kayhan("junior developer", 150);
        form = ali.makeForm("shrubbery creation", "salary");

        kayhan.signForm(*form);
        kayhan.executeForm(*form);
        delete form;
        form = NULL;
        std::cout << "aaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
        delete form;
        form = NULL;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 3 | ->" << std::endl;
        Intern ali;
        Bureaucrat yunus("product manager", 10);
        form = ali.makeForm("begin boss", "monster");

        yunus.signForm(*form);
        yunus.executeForm(*form);
        delete form;
        form = NULL;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
        delete form;
        form = NULL;
    }

    return (0);
}