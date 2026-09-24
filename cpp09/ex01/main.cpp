#include <iostream>
#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2){
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    RPN rpn;
    try{
        rpn.Run(av[1]);
    } catch(std::exception& e){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}