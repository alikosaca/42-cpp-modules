#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* arr, std::size_t len, F fun){
    if (!arr || len == 0 || !fun){
        return ;
    }
    for (std::size_t i = 0; i < len; i++) {
        fun(arr[i]);
    }
}

#endif 
