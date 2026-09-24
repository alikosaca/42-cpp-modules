#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if (ac != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange bitcoin;
        bitcoin.processInput(av[1]);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
/*
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.

*/

/*
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
*/