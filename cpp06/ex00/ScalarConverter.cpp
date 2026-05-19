#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>


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

    while (i < 6 && literal != pseudoLiterals[i]){
        i++;
    }
    if (i < 6 && literal == pseudoLiterals[i]){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    	if (literal == "nan" || literal == "nanf"){
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff"){
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        } else if (literal == "-inf" || literal == "-inff"){
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return true;
    }
    return false;
}


static void castChar(const double cast){
    std::cout << "char: ";
    if (cast < 0.0 || cast > 127.0){
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(cast);
    if (std::isprint(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

}

static void castInt(const double cast){
    std::cout << "int: ";
    if (cast < std::numeric_limits<int>::min() || cast > std::numeric_limits<int>::max()){
        std::cout << "impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(cast);
    std::cout << cast << std::endl;
}

static void castDouble(const double cast){
    std::cout << "double: ";
    if (cast == std::floor(cast)) {
        std::cout << cast << ".0" << std::endl;
    } else {
        std::cout << cast << std::endl;
    }
}

static void castFloat(const double cast){
    std::cout << "float: ";
    float f = static_cast<float>(cast);
    if (f == std::floor(f)) {
        std::cout << f << ".0f" << std::endl;
    } else {
        std::cout << f << "f" << std::endl;
    }
}

static void convertType(const std::string &literal){
    char* end;
    double cast;
    
    if (literal.length() == 1 && !isdigit(literal[0])) {
        cast = static_cast<double>(literal[0]);    
    } else{
        cast = std::strtod(literal.c_str(), &end);
        if ((*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) || (end == literal.c_str())) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    castChar(cast);
    castInt(cast);
    castFloat(cast);
    castDouble(cast);
}


void ScalarConverter::Convert(const std::string &literal){
    if (pseudoLiterals(literal)){
        return;
    }
    convertType(literal);
}
