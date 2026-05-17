#include "Span.hpp"
#include <algorithm>
#include <iterator>


Span::Span() : _maxSize(42){}
Span::Span(const unsigned int N) : _maxSize(N){}
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers){}

Span& Span::operator=(const Span& other){
    if (this != &other){
        this->_maxSize = other._maxSize;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number){
    if (_numbers.size() >= _maxSize){
        throw SpanIsFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const{
    if (_numbers.size() < 2){
        throw NotEnoughElementsException();
    }
    std::vector<int> v = _numbers;
    std::sort(v.begin(), v.end());
    int minDis = v[1] - v[0];
    int isMinDis = 0;
    for (size_t i = 2; i < v.size(); i++){
        isMinDis = v[i] - v[i - 1];
        if (isMinDis < minDis){
            minDis = isMinDis;
        }
    }
    return minDis;
}

int Span::longestSpan() const{
    if (_numbers.size() < 2){
        throw NotEnoughElementsException();
    }
    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
    return (*max - *min);
}

const char* Span::SpanIsFullException::what() const throw(){
    return "Error! Span is full, cannot add more numbers.";
}

const char* Span::NotEnoughElementsException::what() const throw(){
    return "Error! Not enough elements to calculate span.";
}
