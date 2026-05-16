#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"



int main(void)
{
    {
        std::cout << "<<VECTOR>>" << std::endl;
        std::vector<int> v;
        v.push_back(21);
        v.push_back(42);
        v.push_back(84);
        v.push_back(2026);
        try{
            std::cout << "<-Test: 42" << std::endl;
            std::vector<int>::iterator i = easyfind(v, 42);
            std::cout << "<-Success-> " << *i << std::endl;
        } catch(const std::exception& e){
            std::cout << "<-Error-> " << e.what() << std::endl;
        }
        std::cout << "---------" << std::endl;
        try{
            std::cout << "<-Test: 43" << std::endl;
            std::vector<int>::iterator i = easyfind(v, 43);
            std::cout << "<-Success-> " << *i << std::endl;
        } catch(const std::exception& e){
            std::cout << "<-Error-> " << e.what() << std::endl;
        }
        std::cout << "---------" << std::endl;
    }
    {
        std::cout << "<<LIST>>>" << std::endl;
        std::list<int> l;
        l.push_back(100);
        l.push_back(101);
        l.push_back(999);
        try{
            std::cout << "<-Test: 101" << std::endl;
            std::list<int>::iterator i = easyfind(l, 101);
            std::cout << "<-Success-> " << *i << std::endl;
        } catch(const std::exception& e){
            std::cout << "<-Error-> " << e.what() << std::endl;
        }
        std::cout << "---------" << std::endl;
        try{
            std::cout << "<-Test: 99" << std::endl;
            std::list<int>::iterator i = easyfind(l, 99);
            std::cout << "<-Success-> " << *i << std::endl;
        } catch(const std::exception& e){
            std::cout << "<-Error-> " << e.what() << std::endl;
        }
        std::cout << "---------" << std::endl;
    }
    return (0);
}