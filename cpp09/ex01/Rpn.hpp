#ifndef RPN
#define RPN

#include <iostream>
#include <string>
#include <stack>

class Rpn {
    private:
        std::stack<int> stack;
    public:
        Rpn();
        Rpn(const Rpn& other);
        Rpn& operator=(const Rpn& other);
        ~Rpn();
        void Calcature(std::string input);

};

#endif 
