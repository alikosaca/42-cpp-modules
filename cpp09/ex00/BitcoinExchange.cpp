#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>

void BitcoinExchange::processInput(std::string input){
    std::ifstream file(input.c_str());
    if (!file.is_open()){
        throw "Input.txt coudnt open";
    }
    std::string line;
    while (std::getline(file, line)){
        std::cout << line << std::endl;
    }
    file.close();
}