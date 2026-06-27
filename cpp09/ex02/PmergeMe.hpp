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
        void pushNums(int ac, char **av);
        void fordJohnsonVec(std::vector<int>& vc);
        std::vector<int> recursiveVecPair(std::vector< std::pair<int, int> >& pairs);
        std::vector< std::pair<int, int> > pushVecPair(std::vector<int>& v);
        class ErrException : public std::exception {
            public : virtual const char* what() const throw();
        };
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void Run(int ac, char **av);
};

#endif 
