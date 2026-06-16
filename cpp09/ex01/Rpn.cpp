#include "Rpn.hpp"
#include <sstream>
#include <string>

Rpn::Rpn() {}
Rpn::Rpn(const Rpn& other) {}

Rpn& Rpn::operator=(const Rpn& other) {}

Rpn::~Rpn() {}

// "9 8 5 * +"


// void CheckToken(std::string token){
//     //if (token.)
// }


void Rpn::Calcature(std::string input){
    std::istringstream s(input);
    std::string token;
    while (s >> token){
        if (token.length() == 1){
            if (std::isdigit(token[0] - '0')){
                stack.push(token[0] - '0');
            }
        }else{
            std::cout << "Error" << std::endl;
        }
    }
}