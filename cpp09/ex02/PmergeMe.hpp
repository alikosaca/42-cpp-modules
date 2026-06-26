#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>
#include <iostream>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        int i;
        void pushNums(int ac, char **av);
        class ErrException : public std::exception {
            public : virtual const char* what() const throw();
        };
    public:
        PmergeMe();
        PmergeMe(int i);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void Run(int ac, char **av);
};

#endif 
