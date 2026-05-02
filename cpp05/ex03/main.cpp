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

    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 1 | ->" << std::endl;
        Intern ali;
        Bureaucrat ibrahim("Boss", 1);
        AForm* form = ali.makeForm("shrubbery creation", "razer");
        std::cout << ibrahim << std::endl;
        std::cout << *form << std::endl;

        ibrahim.signForm(*form);
        ibrahim.executeForm(*form);
        delete form;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 2 | ->" << std::endl;
        Intern ali;
        Bureaucrat kayhan("junior developer", 150);
        AForm* form = ali.makeForm("shrubbery creation", "salary");

        kayhan.signForm(*form);
        kayhan.executeForm(*form);
        delete form;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 3 | ->" << std::endl;
        Intern ali;
        Bureaucrat yunus("product manager", 10);
        AForm* form = ali.makeForm("begin boss", "monster");

        yunus.signForm(*form);
        yunus.executeForm(*form);
        delete form;
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    catch (const std::string& s) {
        std::cout << s << std::endl;
    }

    return (0);
}