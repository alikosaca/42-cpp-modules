#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        void Run(std::string input);
        bool CheckStatus();
        void Calcature(char o);

};

#endif 
