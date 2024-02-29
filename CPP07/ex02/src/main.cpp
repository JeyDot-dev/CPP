#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main_subject()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(int, char**)
{
    std::cout << "****TEST THE MAIN FROM THE SUBJECT" << std::endl;
    main_subject();
    std::cout << "****MY TESTS" << std::endl;
    Array<std::string>  str_tests(4);
    Array<float>        wont_work(3);
    try
    {
        str_tests[0] = "Wapiti";
        str_tests[1] = "Margaritha";
        str_tests[2] = "Perceval";
        str_tests[3] = "Moon";
        std::cout << str_tests << std::endl;
//        wont_work = str_tests;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
