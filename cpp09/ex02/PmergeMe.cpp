#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::validateNums(int ac, char **av, std::vector<int>& before){
    for (int i = 1; i < ac; i++){
        if (av[i][0] == '\0') throw ErrException();
        for (int j = 0; av[i][j] != '\0'; j++){
            if (!(av[i][j] >= '0' && av[i][j] <= '9')) throw ErrException();
        }
        long long numS = std::atoll(av[i]);
        if (numS > std::numeric_limits<int>::max() || numS < 0) throw ErrException();
        before.push_back(static_cast<int>(numS));
    }
}

void PmergeMe::pushVec(int ac, char **av){
    for (int i = 1; i < ac; i++){
        vec.push_back(static_cast<int>(std::atoll(av[i])));
    }
}

void PmergeMe::pushDeq(int ac, char **av){
    for (int i = 1; i < ac; i++){
        deq.push_back(static_cast<int>(std::atoll(av[i])));
    }
}

std::vector< std::pair<int, int> > PmergeMe::pushVecPair(std::vector<int>& v){
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

std::vector<int> PmergeMe::recursiveVecPair(std::vector< std::pair<int, int> >& pairs){
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
    std::vector<int> mainChain = recursiveVecPair(nPair);
    if (hasSt == true){
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), st), st);
    }
    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        std::vector<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), it->first);
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, it->second);
        mainChain.insert(insertPos, it->second);
    }
    return mainChain;
}

void PmergeMe::fordJohnsonVec(){
    if (vec.size() < 2) return;
    int straggler = 0;
    bool hasStraggler = false;
    if (vec.size() % 2 != 0){
        hasStraggler = true;
        straggler = vec.back();
    }
    std::vector< std::pair<int, int> > p = pushVecPair(vec);
    std::vector<int> mainChain = recursiveVecPair(p);
    if (hasStraggler){
        std::vector<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, straggler);
        mainChain.insert(insertPos, straggler);
    }
    vec = mainChain;
}

std::deque< std::pair<int, int> > PmergeMe::pushDeqPair(std::deque<int>& v){
    std::deque< std::pair<int, int> > p;
    for(std::deque<int>::iterator it = v.begin(); it != v.end(); it++){
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

std::deque<int> PmergeMe::recursiveDeqPair(std::deque< std::pair<int, int> >& pairs){
    if (pairs.size() == 1) {
            std::deque<int> mainChain;
            mainChain.push_back(pairs[0].second);
            mainChain.push_back(pairs[0].first);
            return mainChain;
    }
    int st = -1;
    bool hasSt = false;
    if (pairs.size() % 2 != 0){
        hasSt = true;
        st = pairs.back().first;
    }
    std::deque< std::pair<int, int> > nPair;
    for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        if (it+1 != pairs.end()){
            if (it->first > (it+1)->first){
                nPair.push_back(std::make_pair(it->first, (it+1)->first));
            } else{
                nPair.push_back(std::make_pair( (it+1)->first, it->first ));
            }
            it++;
        }
    }
    std::deque<int> mainChain = recursiveDeqPair(nPair);
    if (hasSt == true){
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), st), st);
    }
    for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++){
        std::deque<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), it->first);
        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, it->second);
        mainChain.insert(insertPos, it->second);
    }
    return mainChain;
}

void PmergeMe::fordJohnsonDeq(){
    if (vec.size() < 2) return;
    int straggler = 0;
    bool hasStraggler = false;
    if (deq.size() % 2 != 0){
        hasStraggler = true;
        straggler = deq.back();
    }
    std::deque< std::pair<int, int> > p = pushDeqPair(deq);
    std::deque<int> mainChain = recursiveDeqPair(p);
    if (hasStraggler){
        std::deque<int>::iterator partnerPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), partnerPos, straggler);
        mainChain.insert(insertPos, straggler);
    }
    deq = mainChain;
}


void PmergeMe::Run(int ac, char** av){
    std::vector<int> before;
    validateNums(ac, av, before);
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = before.begin(); it != before.end(); it++){
        std::cout << *it;
        if (it+1 != before.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    double vecStart = getTime();
    pushVec(ac, av);
    fordJohnsonVec();
    double vecEnd = getTime();
    double deqStart = getTime();
    pushDeq(ac, av);
    fordJohnsonDeq();
    double deqEnd = getTime();
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        std::cout << *it;
        if (it+1 != vec.end()){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of "
          << vec.size() << " elements with std::vector : "
          << std::fixed << std::setprecision(5)
          << (vecEnd - vecStart) << " us" << std::endl;

    std::cout << "Time to process a range of "
          << deq.size() << " elements with std::deque : "
          << std::fixed << std::setprecision(5)
          << (deqEnd - deqStart) << " us" << std::endl;
}

double PmergeMe::getTime() const {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ((ts.tv_sec * 1000000) + (ts.tv_nsec / 1000));
}

const char* PmergeMe::ErrException::what() const throw() {
    return "Error";
}
