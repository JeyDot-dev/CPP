#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#define N   5 

int main(void)
{
    std::srand(time(NULL));
    Span a(N);
    for (int i = 0; i < N; i++)
        a.addNumber(std::rand() % 101);
    std::cout << a <<std::endl;
    std::cout <<    "short: " << a.shortestSpan() <<
                    "\nlong: " << a.longestSpan() << std::endl;

    try{a.addNumber(1);}
    catch(std::exception& e){std::cout << e.what() << std::endl;}
    try{
        Span b(3);
        b.shortestSpan();
    }catch(std::exception &e){std::cout << e.what() << std::endl;}
}
