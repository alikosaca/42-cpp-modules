#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void){
    int random = std::rand() % 3;

    if (random == 0){
        return (new A());
    } else if (random == 1){
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
    for (std::size_t i = 0; i < 5; i++) {
        std::cout << "<<<---Test " << (i + 1) << "--->" << std::endl;
        Base* randomBase = generate();
        std::cout << "identify(*)" << std::endl;
        identify(randomBase);
        std::cout << "identify(&)" << std::endl;
        identify((*randomBase));
        std::cout << "<<<--->>>" << std::endl;
        delete randomBase;
    }
    return (0);
}