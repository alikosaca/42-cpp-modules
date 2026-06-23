#include <PmergeMe.hpp>

PmergeMe::PmergeMe() : i(0) {}

PmergeMe::PmergeMe(int new_i) : i(new_i){}

PmergeMe::PmergeMe(const PmergeMe& other) : i(other.i){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        this->i = other.i;
    }
    return *this;
}


