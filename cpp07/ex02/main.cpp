#include <iostream>
#include <string>
#include "Array.hpp"

int main(void) {
    std::cout << "-------------" << std::endl;
    Array<int> a(10);
    std::cout << "a size: " << a.size() << std::endl;
    for(int i = 0; i < (int)a.size(); i++){
        a[i] = i;
    }
    for(int i = 0; i < (int)a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-----copy-------" << std::endl;
    Array<int> b(a);
    std::cout << "b size: " << b.size() << std::endl;
    for(int i = 0; i < (int)b.size(); i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "change b" << std::endl;
    for(int i = 0; i < (int)b.size(); i++){
        b[i] += 42;
    }
    std::cout << "-------------" << std::endl;
    std::cout << "------assigment------" << std::endl;
    Array<int> c;
    c = b;
    for(int i = 0; i < (int)c.size(); i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-----throw-------" << std::endl;
    try{
        a[42] = 42;
    } catch(std::exception& e){
        std::cout << "err main: " << e.what() << std::endl;
    }
    std::cout << "-------------" << std::endl;
    return 0;
}