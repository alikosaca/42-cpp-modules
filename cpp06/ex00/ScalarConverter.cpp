#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return ((*this));
}

ScalarConverter::~ScalarConverter(){}


static bool pseudoLiterals(const std::string &literal){
    std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int i = 0;

    while (literal != pseudoLiterals[i]){
        i++;
    }
    if (literal == pseudoLiterals[i]){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
    	if (literal == "nan" || literal == "nanf"){
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }else if (literal == "+inf" || literal == "+inff"){
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
        return (true);
    }
}

void ScalarConverter::Convert(const std::string &literal){
    if (pseudoLiterals(literal)){
        return;
    }
    
}
