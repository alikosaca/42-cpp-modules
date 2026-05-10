#include "Array.hpp"
#include <stdexcept>


template <typename T>
Array<T>::Array() : _size(0), _element(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n){
    _size = n;
    if (n == 0){
        _element = NULL;
    } else{
        _element = new T[n]();
    }
}

template <typename T>
Array<T>::Array(const Array& other){
    this->_size = other.size();
    if (other.size() == 0){
        this->_element = NULL;
    } else{
        this->_element = new T[_size]();
        for (int i = 0; i < (int)_size; i++){
            this->_element[i] = other._element[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
    if (this != &other){
        delete[] this->_element;
        this->_size = other.size();
        if (_size == 0){
            this->_element = NULL;
        } else{
            this->_element = new T[_size]();
            for (int i = 0; i < (int)_size; i++){
                this->_element[i] = other._element[i];
            }
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(){
    if (_element){
        delete[] _element;
        _element = NULL;
    }
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
    if (n >= _size){
        throw std::out_of_range("Array index out of range");
    }
    return _element[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const{
    if (n >= this->size()){
        throw std::out_of_range("Array index out of range");
    }
    return _element[n];
}

template <typename T>
unsigned int Array<T>::size() const{ return _size; }