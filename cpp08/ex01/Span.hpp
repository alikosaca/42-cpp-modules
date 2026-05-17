#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>


class Span {
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(const unsigned int _maxSize);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        class SpanIsFullException : public std::exception{
            virtual const char* what() const throw();
        };
        class NotEnoughElementsException : public std::exception{
            virtual const char* what() const throw();
        };
};

#endif 
