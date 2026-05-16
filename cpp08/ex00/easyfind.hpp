#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class ValueNotFoundException : public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Ups! Value not found!";
        };
};

template <typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator i = std::find(container.begin(), container.end(), value);
    if (i == container.end()){
        throw ValueNotFoundException();
    }
    return i;
}



#endif 
