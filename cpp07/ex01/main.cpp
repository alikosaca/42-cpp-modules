#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const & x){
    std::cout << "< " <<  x << " >" << std::endl;
}

void upgradeNum(int& num){
    num += 42;
}

void nextWrod(char& c){
    if (c == 'z'){
        c -= 25;
    }else{
        c++;
    }
}

int main(void) {
    std::cout << "<< INT >>---" << std::endl;
    int arrNum[] = {1, 2, 3, 4, 5};
    std::size_t lenNum = sizeof(arrNum) / sizeof(arrNum[0]);
    ::iter(arrNum, lenNum, printElement<int>);

    std::cout << "-------------" << std::endl;
    ::iter(arrNum, lenNum, upgradeNum);
    ::iter(arrNum, lenNum, printElement<int>);

    std::cout << "<< CHAR >>---" << std::endl;
    char arrWord[3] = {'a', 'c', 'z'};
    std::size_t lenWords = sizeof(arrWord) / sizeof(arrWord[0]);
    ::iter(arrWord, lenWords, nextWrod);
    ::iter(arrWord, lenWords, printElement<char>);

    std::cout << "-------------" << std::endl;
    return 0;
}