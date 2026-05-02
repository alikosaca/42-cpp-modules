#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

#include <ctime>

int main(void){
    std::srand(std::time(NULL));

    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 1 | ->" << std::endl;
        Bureaucrat norm("Norminette", 42);
        ShrubberyCreationForm form("Home");
        std::cout << norm << std::endl;
        std::cout << form << std::endl;

        norm.signForm(form);
        norm.executeForm(form);
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 2 | ->" << std::endl;
        Bureaucrat norm("Norminette", 1);
        RobotomyRequestForm form("Home");
        std::cout << norm << std::endl;
        std::cout << form << std::endl;

        norm.signForm(form);
        norm.signForm(form);
        norm.executeForm(form);
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 3 | ->" << std::endl;
        Bureaucrat norm("Norminette", 1);
        PresidentialPardonForm form("Home");
        std::cout << norm << std::endl;
        std::cout << form << std::endl;

        norm.executeForm(form);
        norm.signForm(form);
        norm.executeForm(form);
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 4 | ->" << std::endl;
        Bureaucrat norm("Norminette", 30);
        PresidentialPardonForm form("Home");
        std::cout << norm << std::endl;
        std::cout << form << std::endl;

        norm.signForm(form);
        norm.executeForm(form);
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    try{
        std::cout << "----------------" << std::endl;
        std::cout << "<- | TEST 5 | ->" << std::endl;
        Bureaucrat norm("Norminette", 50);
        RobotomyRequestForm form("Home");
        std::cout << norm << std::endl;
        std::cout << form << std::endl;

        norm.signForm(form);
        norm.executeForm(form);
    } catch(std::exception &e){
        std::cout << "ups!: " << e.what() << std::endl;
    }
    return (0);
}