#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#define N   5 

int main(void)
{
    std::cout << "---------TEST 1" << std::endl;
    std::srand(time(NULL));
    Span a(N);
    for (int i = 0; i < N; i++)
        a.addNumber(std::rand() % 101);
    std::cout << a  <<std::endl;
    std::cout <<    "short: "   << a.shortestSpan() <<
                    "\nlong: "  << a.longestSpan()  << std::endl;

    std::cout << "\n---------TEST 2" << std::endl;
    try{a.addNumber(1);}
    catch(std::exception& e){std::cerr << e.what() << std::endl;}

    std::cout << "\n---------TEST 3" << std::endl;
    try{
        Span b(3);
        b.addNumber(1);
        b.shortestSpan();
    }catch(std::exception &e){std::cerr << e.what() << std::endl;}

    std::cout << "\n---------TEST 4" << std::endl;
    try{
        std::vector<int> test;
        for (int i = 0; i < N; i++)
            test.push_back(i);
        Span c(N);
        c.addNumber(test.begin(), test.end());
        std::cout << c << std::endl;
    }catch(std::exception& e){std::cerr << e.what() << std::endl;}
}
