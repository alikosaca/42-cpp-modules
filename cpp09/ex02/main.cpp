#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    if (ac < 2){
        std::cerr << "Usage: ./PmergeMe numbers" << std::endl;
        return 2;
    }
    try {
        PmergeMe merge;
        merge.Run(ac, av);
    } catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}