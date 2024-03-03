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
    BitcoinExchange b(a);
    BitcoinExchange c = a;

//    a.printDb();
    std::cout << "ORIGINAL" << std::endl;
    std::cerr << "ORIGINAL" << std::endl;
    a.outputPrice(av[1]);
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    std::cerr << "COPY CONSTRUCTOR" << std::endl;
    b.outputPrice(av[1]);
    std::cout << "COPY ASSIGNATION" << std::endl;
    std::cerr << "COPY ASSIGNATION" << std::endl;
    c.outputPrice(av[1]);
}
