#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./btc [file]" << std::endl;
        return 1;
    }
    BitcoinExchange a;

    a.outputPrice(av[1]);
}
