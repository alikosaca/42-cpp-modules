#include "Rpn.hpp"
#include <sstream>
#include <string>

Rpn::Rpn() {}
Rpn::Rpn(const Rpn& other) : stack(other.stack){}

Rpn& Rpn::operator=(const Rpn& other) {
    if (this != &other){
        stack = other.stack;
    }
    return *this;
}

Rpn::~Rpn() {}

// "9 8 5 * +"


// void CheckToken(std::string token){
//     //if (token.)
// }

bool IsOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Rpn::CheckStatus(){
    return (stack.size() >= 2);
}

void Rpn::Calcature(char o){
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
            stack.push(n2 / n1);
            break;
        default:
            break;
    }
    //return c == '+' || c == '-' || c == '*' || c == '/';
}
// "9 8 *"

void Rpn::Run(std::string input){
    std::istringstream s(input);
    std::string token;
    while (s >> token){
        if (token.length() == 1 && std::isdigit(token[0])){
            stack.push(token[0] - '0');
        } else if (token.length() == 1 && IsOperator(token[0]) && CheckStatus()){
            Calcature(token[0]);
        } else{
            std::cout << "Error" << std::endl;
            return ;
        }
    }
    std::cout << stack.top() << std::endl;
}