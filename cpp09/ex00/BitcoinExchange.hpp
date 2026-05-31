#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>

class BitcoinExchange {
    private:
        float price;
        int date;
        int month;
        int year;
    public:
        //BitcoinExchange();
        //BitcoinExchange(const BitcoinExchange& other);
        //BitcoinExchange& operator=(const BitcoinExchange& other);
        //~BitcoinExchange();

        void processInput(std::string Input);
        void DateIsValid(std::string date);
        void ValueIsValid(std::string valueS);
};

#endif 
