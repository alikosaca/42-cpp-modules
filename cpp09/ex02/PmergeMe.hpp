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
        void fordJohnsonDeq(std::deque<int>& vc);
        std::deque<int> recursiveDeqPair(std::deque< std::pair<int, int> >& pairs);
        std::deque< std::pair<int, int> > pushDeqPair(std::deque<int>& v);
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
