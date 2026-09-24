#include "RPN.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& other) : stack(other.stack){}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) stack = other.stack;
    return *this;
}

RPN::~RPN() {}

bool IsOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::CheckStatus(){
    return (stack.size() >= 2);
}

void RPN::Calcature(char o){
    int n1 = stack.top();
    stack.pop();
    int n2 = stack.top();
    stack.pop();
    switch (o)
    {
        case '+':
            stack.push(n2 + n1);
            break;
        case '-':
            stack.push(n2 - n1);
            break;
        case '*':
            stack.push(n2 * n1);
            break;
        case '/':
            if (n1 != 0) stack.push(n2 / n1);
            else throw std::runtime_error("");
            break;
        default:
            break;
    }
}

void RPN::Run(std::string input){
    std::istringstream s(input);
    std::string token;
    while (s >> token){
        if (token.length() == 1 && std::isdigit(token[0])) stack.push(token[0] - '0');
        else if (token.length() == 1 && IsOperator(token[0]) && CheckStatus()) Calcature(token[0]);
        else throw std::runtime_error("");
    }
    if (stack.size() == 1) std::cout << stack.top() << std::endl;
    else throw std::runtime_error("");
}