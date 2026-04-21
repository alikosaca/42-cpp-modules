#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    try{
        std::cout << "<<<--- Test 1 --->>>" << std::endl;
        Bureaucrat Human("Norminette", 1);
        Form form("white", false, 42, 1);
        std::cout << form << std::endl;
        Human.signForm(form);
        std::cout << form << std::endl;
    } catch(std::exception& e){
        std::cout << "exception test 1 -> " << e.what() << std::endl;
    }

    try{
        std::cout << "<<<--- Test 2 --->>>" << std::endl;
        Bureaucrat Human("Norminette", 1);
        Form form("white", false, 0, 1);
        std::cout << form << std::endl;
    } catch(std::exception& e){
        std::cout << "exception test 2 -> " << e.what() << std::endl;
    }

    try{
        std::cout << "<<<--- Test 3 --->>>" << std::endl;
        Bureaucrat Human("Norminette", 42);
        Form form("white", false, 40, 40);
        std::cout << form << std::endl;
        Human.signForm(form);
        std::cout << form << std::endl;
    } catch(std::exception& e){
        std::cout << "exception test 3 -> " << e.what() << std::endl;
    }
    return (0);
}