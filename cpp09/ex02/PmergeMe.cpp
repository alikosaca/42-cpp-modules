#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
#include <sys/time.h>

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

void PmergeMe::pushNums(int ac, char **av){
    vec.push_back(std::atoi(av[i]));
    for (int i = 1; i < ac; i++){
        for (int j = 0; av[i][j] != '\0'; j++){
            if (!(av[i][j] >=  '0' && av[i][j] <= '9')) throw ErrException();
        }
        std::string num = (av[i]);
        long long numS = std::atoll(num.c_str());
        if (numS > std::numeric_limits<int>::max() || numS < 0) throw ErrException();
        vec.push_back(static_cast<int>(numS));
        deq.push_back(static_cast<int>(numS));
    }
}

std::vector< std::pair<int, int> > pushPair(std::vector<int>& v){
    std::vector< std::pair<int, int> > p;
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
    return p;
}

std::vector<int> recursivePair(std::vector< std::pair<int, int> >& pairs){
    if (pairs.size() == 1) {
            std::vector<int> mainChain;
            mainChain.push_back(pairs[0].second);
            mainChain.push_back(pairs[0].first);
            return mainChain;
    }
    int st = -1;
    bool hasSt = false;
    if (pairs.size() % 2 != 0){
        hasSt = true;
        std::cout << "test2---" << std::endl;
        std::cout << pairs.back().first << std::endl;
        std::cout << "test2---" << std::endl;
        st = pairs.back().first;
    }
    std::vector< std::pair<int, int> > nPair;
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        if (it+1 != pairs.end()){
            if (it->first > (it+1)->first){
                nPair.push_back(std::make_pair(it->first, (it+1)->first));
            } else{
                nPair.push_back(std::make_pair( (it+1)->first, it->first ));
            }
            it++;
        }
    }
    std::vector<int> mainChain = recursivePair(nPair); // 5, 8 --- 2
    if (hasSt == true){
        if (mainChain[0] > st){
            mainChain.insert(mainChain.begin(), st);
        } else if(mainChain[1] > st) {
            mainChain.insert(mainChain.begin() + 1, st);
        } else{
            mainChain.insert(mainChain.begin() + 2, st);
        }
    }
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        std::vector<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), it->first);
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, it->second);
        mainChain.insert(insertPos, it->second);
    }
    return mainChain;
}

void fordJohnson(std::vector<int>& vc){
    int straggler = 0;
    bool hasStraggler = false;
    if (vc.size() % 2 != 0){
        hasStraggler = true;
        straggler = vc.back(); //3
    }
    std::vector< std::pair<int, int> > p = pushPair(vc);
    std::vector<int> mainChain = recursivePair(p);
    if (hasStraggler){
        std::vector<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, straggler);
        mainChain.insert(insertPos, straggler);
    }
    std::cout << "---" << std::endl;
    for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++){
        std::cout << "chain: " << *it << std::endl;
    }
    std::cout << "---" << std::endl;
}

void PmergeMe::Run(int ac, char** av){
    //!parse
    //*push number to vc
    pushNums(ac, av);
    std::cout << deq[0] << std::endl;
    fordJohnson(vec);
}


const char* PmergeMe::ErrException::what() const throw() {
    return "Error";
}