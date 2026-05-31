#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;
    public:
        //BitcoinExchange();
        //BitcoinExchange(const BitcoinExchange& other);
        //BitcoinExchange& operator=(const BitcoinExchange& other);
        //~BitcoinExchange();

        void processInput(std::string Input);
        void InitDatabase();
        std::string DateIsValid(std::string date);
        float ValueIsValid(std::string valueS);
        //void InitInput();
};

#endif 
