#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if (this != &other){
        data = other.data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::DateIsValid(std::string line){   
    if (line.length() == 0) return ("null");
    if (line.length() < 14) throw "bad input => "+ line;
    std::string date = line.substr(0, 13);
    if (date[4] != '-' || date[7] != '-') throw "file in invalid format";
    if (date[10] != ' ' || date[11] != '|' || date[12] != ' ') throw "file in invalid format";
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 999 || (month > 12 || month < 0) || (day > 31 || day < 0)) throw "Invalid date information.";
    return date;
}

float BitcoinExchange::ValueIsValid(std::string valueS){
    if (valueS.length() > 4 || valueS.length() == 0) throw "incorrect value! must between 0 and 1000 number";
    float value = std::atof(valueS.c_str());
    if (value > 1000) throw "too large a number.";
    else if (value < 0) throw "not a positive number.";
    return value;
}

void BitcoinExchange::InitDatabase(){
    std::ifstream database("data.csv");
    if (!database.is_open()) throw "data.csv could not open file";
    std::string line;
    std::getline(database, line);
    while (std::getline(database, line)){
        if (line.size() >= 12) this->data[line.substr(0, 10)] = std::atof(line.substr(11).c_str());
    }
    database.close();
}

void BitcoinExchange::Exchange(std::string& date, float& value){
    std::map<std::string, float>::iterator it = this->data.lower_bound(date);
    if (it->first != date && it != this->data.begin()) --it;
    float res = value * it->second;
    std::cout << date << " => " << value << " = " << res << std::endl;
}

void BitcoinExchange::processInput(std::string input){    
    InitDatabase();
    std::ifstream file(input.c_str());
    if (!file.is_open()) throw "could not open file.";
    std::string line;
    std::string date;
    float value;
    std::getline(file, line);
    while (std::getline(file, line)){
        try{
            date = DateIsValid(line);
            if (date == "null") continue;
            value = ValueIsValid(line.substr(13));
            Exchange(date, value);
        }catch (const std::string& e) {
            std::cout << "Error: " << e << std::endl;
        }catch(const char* e){
            std::cout << "Error: " << e << std::endl;
        }
    }
    file.close();
}

