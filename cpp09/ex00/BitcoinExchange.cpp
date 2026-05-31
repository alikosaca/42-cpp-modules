#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
//#include <exception>


void BitcoinExchange::DateIsValid(std::string date){   
    if (date[4] != '-' || date[7] != '-' || date[11] != '|'){
        throw "bad input";
    } //line.length() > 14 ||
    //! tarih kontorlü yap
    //? input.txt en altta boşluk olabilir mi?
    if (date[10] != ' ' || date[11] != '|' || date[12] != ' '){
        throw "bad input2";
    }
    //std::string y = line.substr(0, 4).c_str();
    //std::string m = line.substr(5, 2).c_str();
    //std::string d = line.substr(8, 2).c_str();
    //std::cout << "year:" << y << ", month:" << m << ", day:" << d << std::endl;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
     if (year < 999 || (month > 12 || month < 0) || (day > 31 || day < 0)){
         throw "date err";
     }
}

void BitcoinExchange::ValueIsValid(std::string valueS){
    if (valueS.length() > 4 || valueS.length() == 0){
       throw "incorrect value! must between 0 and 1000 number";
    }
    float value = std::atoi(valueS.c_str());
    if (value > 1000 || value < 0){
       throw "value must between 0 and 1000";
    }
}

void BitcoinExchange::InitDatabase(){
    std::ifstream database("data.csv");
    if (!database.is_open()){
        throw "data.csv coudnt open!";
    }
    std::string line;
    std::getline(database, line);
    while (std::getline(database, line)){
        if (line.size() >= 12){
            this->data[line.substr(0, 10)] = std::atof(line.substr(11).c_str());;
        }
    }
    database.close();
}

void BitcoinExchange::processInput(std::string input){    
    try{
        InitDatabase();
    } catch(const char* e){
        std::cout << "ERR! Database" << e << std::endl;
        return;
    }
    std::ifstream file(input.c_str());
    if (!file.is_open()){
        throw "Input.txt coudnt open";
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)){
        std::cout << line << std::endl;
        try{
            DateIsValid(line.substr(0, 13));
            ValueIsValid(line.substr(13));

        }catch(const char* e){
            std::cout << "err: " << e << std::endl;
        }
    }
    file.close();
}

