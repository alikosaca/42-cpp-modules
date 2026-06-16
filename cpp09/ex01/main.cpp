#include <iostream>
#include "Rpn.hpp"

int main(int ac, char** av)
{
    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    Rpn rpn;
    rpn.Run(av[1]);
    return 0;
}