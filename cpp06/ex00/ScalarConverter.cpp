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

    while (i < pseudoLiterals->length() && literal != pseudoLiterals[i]){
        i++;
    }
    if (i < pseudoLiterals->length() && literal == pseudoLiterals[i]){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
    	if (literal == "nan" || literal == "nanf"){
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }else if (literal == "+inf" || literal == "+inff"){
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
        return true;
    }
}

static bool convertType(const std::string &literal){
    char* end;
    double val = std::strtod(literal.c_str(), &end);
    
    if (literal.length() == 1 && !isdigit(literal[0])) {
        double val = static_cast<double>(literal[0]);
        return true;
    } else if ((*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) || (end == literal.c_str())) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return false;
    } else{
        return true;
    }
}

void ScalarConverter::Convert(const std::string &literal){
    if (!pseudoLiterals(literal)){
        return;
    }
    if (!convertType(literal)){
        return;
    }
}
