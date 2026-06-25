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

void pushPair(std::vector<int>& v, std::vector< std::pair<int, int> >& p){
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        if (it+1 != v.end()){
            if (*it > *(it+1)){
                p.push_back(std::make_pair(*it, *(it+1)));
            } else{
                p.push_back(std::make_pair( *(it+1), *it ));
            }
            it++;
        }
    }
}

void swapPair(std::vector< std::pair<int, int> >& p){
    for (std::vector< std::pair<int, int> >::iterator it = p.begin(); it != p.end(); it++){
        if (it+1 != p.end()){
            if (it->second > it->first){
                int swap = it->first;
                it->first = it->second;
                it->second = swap;
                it++;
            }
        }
    }
}

void sortMainChain(std::vector< std::pair<int, int> >& p, std::vector<int>& mainChain){
    for (std::vector< std::pair<int, int> >::iterator it = p.begin(); it != p.end(); it++){
        mainChain.push_back(it->first);
    }
}

void PmergeMe::Run(int ac, char** av){
    //!parse
    //*push number to vc
    std::vector<int> v;
    std::vector< std::pair<int, int> > p;
    std::vector<int> mainChain;
    std::vector<int> chain;
    pushNums(ac, av, v);
    int straggler_map = 0;
    if (v.size() % 3 != 0){
        straggler_map = v.size() + 1; //*index olarak düşündüğümüz için +1 yazdık.
    }
    std::cout << "straggler_map: " << straggler_map << std::endl;
    pushPair(v, p);
    swapPair(p);
    sortMainChain(p, mainChain);

}


    // for (std::vector< std::pair<int, int> >::iterator it = p.begin(); it != p.end(); it++){
    //     std::cout << "---" << std::endl;
    //     std::cout << "first: " << it->first << std::endl;
    //     std::cout << "second: " << it->second << std::endl;
    //     std::cout << "---" << std::endl;
    // }
    // std::cout << "-------------------------------------" << std::endl;
    // for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++){
    //     std::cout << "---" << std::endl;
    //     std::cout << "chain: " << *it << std::endl;
    //     std::cout << "---" << std::endl;
    // }