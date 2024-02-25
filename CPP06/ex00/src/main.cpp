#include "ScalarConverter.hpp"
int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "pls, enter numbers" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++)
    {
        std::cout << "**Converting: "<< av[i] << std::endl;
        ScalarConverter::convert(av[i]);
        std::cout << "------------------" << std::endl;
    }
    return 0;
}
