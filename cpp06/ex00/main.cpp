#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::Convert(argv[1]);
    return 0;
}
