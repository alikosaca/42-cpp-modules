#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        float price;
        std::string date;
        std::map<std::string, float> data;
        int month;
        int year;
    public:
        //BitcoinExchange();
        //BitcoinExchange(const BitcoinExchange& other);
        //BitcoinExchange& operator=(const BitcoinExchange& other);
        //~BitcoinExchange();

        void processInput(std::string Input);
        void InitDatabase();
        void DateIsValid(std::string date);
        void ValueIsValid(std::string valueS);
};

#endif 
