#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>

class PmergeMe {
    private:
        std::vector< std::pair<int, int> > vec;
        int i;
    public:
        PmergeMe();
        PmergeMe(int i);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void Run(int ac, char **av);
};

#endif 
