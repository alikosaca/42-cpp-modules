#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void){
    int random = std::rand();

    if (random % 2 == 0){
        return (new A());
    } else if (random % 3 == 0){
        return (new B());
    } else{
        return (new C());
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p)){
        std::cout << "-> A |" << std::endl;
    } else if (dynamic_cast<B*>(p)){
        std::cout << "-> B |" << std::endl;
    } else if (dynamic_cast<C*>(p)){
        std::cout << "-> C |" << std::endl;
    } else {
        std::cout << "-> undefined type! |" << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception& e) {
        std::cout << "| " << e.what() << " |" << std::endl;
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception& e) {
            std::cout << "| " << e.what() << " |" << std::endl;
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception& e) {
                std::cout << "| Unknown type |" << std::endl;
            }
        }
    }
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    return (0);
}