#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    Data cadet;
    cadet.nickName = "akosaca";
    cadet.age = 22;

    std::cout << "Nick name: " << cadet.nickName << ", ";
    std::cout << "Age:" << cadet.age << std::endl;

    uintptr_t raw = Serializer::serialize(&cadet);
    std::cout << "Serialized: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized: " << ptr << std::endl;

    if (&cadet == ptr){
        std::cout << "Success! Adress is same" << std::endl;
        std::cout << "Nick name: " << ptr->nickName << ", ";
        std::cout << "Age:" << ptr->age << std::endl;
    } else{
        std::cout << "Error: Something went wrong!" << std::endl;
    }
}