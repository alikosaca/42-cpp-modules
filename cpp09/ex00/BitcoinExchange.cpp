#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <stdexcept>
#include <cctype>

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
    if (line[10] != ' ' || line[11] != '|' || line[12] != ' ') throw std::runtime_error("file in invalid format");
    std::string date = line.substr(0, 10);
    for (size_t i = 0; i < date.length(); i++){
        if (i == 4 || i == 7) {
            if (date[i] != '-') throw std::runtime_error("file in invalid format"); 
        }
        else if (!std::isdigit(date[i])) {
            throw std::runtime_error("file in invalid format");
        }
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if ((month > 12 || month < 1) || (day > 31 || day < 1)) throw std::runtime_error("bad input => " + line);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year / 4 * 4 == year) daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1]) throw std::runtime_error("bad input => " + line);

    return date;
}

float BitcoinExchange::ValueIsValid(std::string valueS){
    int dots = 0;
    for (size_t i = 0; i < valueS.length(); i++){
        if (valueS[i] == '.') dots++;
        else if (i == 0 && valueS[i] == '-') continue;
        else if (!std::isdigit(valueS[i])) throw std::runtime_error("bad input => " + valueS);
    }
    if (dots > 1) throw std::runtime_error("bad input => " + valueS);
    if (valueS[0] == '-') throw std::runtime_error("not a positive number.");
    float value = std::atof(valueS.c_str());
    if (value > 1000) throw std::runtime_error("too large a number.");
    return value;
}

void BitcoinExchange::InitDatabase(){
    std::ifstream database("data.csv");
    if (!database.is_open()) throw std::runtime_error("data.csv could not open file");
    std::string line;
    std::getline(database, line);
    while (std::getline(database, line)){
        if (line.size() >= 12) this->data[line.substr(0, 10)] = std::atof(line.substr(11).c_str());
    }
    database.close();
}

void BitcoinExchange::Exchange(std::string& date, float& value){
    std::map<std::string, float>::iterator it = this->data.upper_bound(date);
    if (it == data.begin()) throw std::runtime_error("no data before => " + date);
    --it;
    std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

void BitcoinExchange::processInput(std::string input){    
    InitDatabase();
    std::ifstream file(input.c_str());
    if (!file.is_open()) throw std::runtime_error("could not open file.");
    std::string line;
    std::string date;
    float value;
    std::getline(file, line);
    while (std::getline(file, line)){
        try{
            if (line.length() < 14) throw std::runtime_error("bad input => " + line);
            date = DateIsValid(line);
            value = ValueIsValid(line.substr(13));
            Exchange(date, value);
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

