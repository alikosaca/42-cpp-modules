#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe() : i(0) {}

PmergeMe::PmergeMe(int new_i) : i(new_i){}

PmergeMe::PmergeMe(const PmergeMe& other) : i(other.i){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        this->i = other.i;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void pushNums(int ac, char **av, std::vector<int>& v){
    for(int i = 1; i < ac; i++){
        v.push_back(std::atoi(av[i]));
    }
}

void PmergeMe::Run(int ac, char** av){
    //!parse
    //*push number to vc
    std::vector<int> v;
    pushNums(ac, av, v);

}