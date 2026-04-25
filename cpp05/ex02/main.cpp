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
    std::srand(static_cast<unsigned int>(std::time(NULL)));


    try{
        std::cout << "a" << std::endl;
        Bureaucrat a("Norminette", 42);
        std::cout << "f" << std::endl;
        ShrubberyCreationForm f("Home");
    
        std::cout << a << std::endl;
        std::cout << "a yazdık" << std::endl;
        std::cout << f << std::endl;
        std::cout << "f yazdık" << std::endl;
    } catch(std::exception &e){
        std::cout << "sorun var: " << e.what() << std::endl;
    }
    return (0);
}