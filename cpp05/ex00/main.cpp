#include "Bureaucrat.hpp"

int main(void){
    try{
        std::cout << "<<<--- Test 1 --->>>" << std::endl;
        Bureaucrat human("Norminette", 1);
        human.incrementGrade();
        std::cout << human << std::endl;
    } catch(std::exception& e){
        std::cout << "exception test 1 -> " << e.what() << std::endl;
    }

    try{
        std::cout << "<<<--- Test 2 --->>>" << std::endl;
        Bureaucrat human("Norminette", 42);
        human.decrementGrade();
        std::cout << human << std::endl;
        human.decrementGrade();
        std::cout << human << std::endl;
    } catch(std::exception& e){
        std::cout << "exception test 2 -> " << e.what() << std::endl;
    }

    try{
        std::cout << "<<<--- Test 3 --->>>" << std::endl;
        Bureaucrat human("Norminette", 150);
        human.decrementGrade();
        std::cout << human << std::endl;
    } catch (std::exception &e){
        std::cout << "exception test 3 -> " << e.what() << std::endl;
    }

    try{
        std::cout << "<<<--- Test 4 --->>>" << std::endl;
        Bureaucrat human("Norminette", 153);
        std::cout << human << std::endl;
    } catch(std::exception &e){
        std::cout << "exception test 4 -> " << e.what() << std::endl;
    }
    return (0);
}