#include <iostream>
#include "MutantStack.hpp"
#include <list>

int subject_main()
{
    std::cout << "--Mutant stack version" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    std::cout << "top:" << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size:" << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    //[...]
    mstack.push(6);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "--List version" << std::endl;
    std::list<int> tha_list;
    tha_list.push_back(1);
    tha_list.push_back(2);
    std::cout << "top:" << tha_list.back() << std::endl;
    tha_list.pop_back();
    std::cout << "size:" << tha_list.size() << std::endl;
    tha_list.push_back(3);
    tha_list.push_back(4);
    tha_list.push_back(5);
    //[...]
    tha_list.push_back(6);
    std::list<int>::iterator itt = tha_list.begin();
    std::list<int>::iterator itte = tha_list.end();
    ++itt;
    --itt;
    while (itt != itte)
    {
        std::cout << *itt << std::endl;
        ++itt;
    }
    std::list<int> ss(tha_list);
    return 0;
}
int main(void)
{
    {
        std::cout << "***TESTING SUBJECT MAIN" << std::endl;
    subject_main();
        std::cout << "***END SUBJECT MAIN" << std::endl;
    }
    {
        std::cout << "***TESTING COPIES" << std::endl;
    MutantStack<int> a;     a.push(42);
    MutantStack<int> b(a);
    MutantStack<int> c;     c = b;
    std::stack<int> d(a);
    std::cout << a.top() << std::endl;
    std::cout << b.top() << std::endl;
    std::cout << c.top() << std::endl;
    std::cout << d.top() << std::endl;
        std::cout << "***END OF COPIES\n" << std::endl;
    }
    {
        std::cout << "***TESTING ITERATORS" << std::endl;
        MutantStack<int>                    a;
        MutantStack<int>::iterator          it;
        MutantStack<int>::reverse_iterator  rit;

        for (size_t i = 0; i < 10; i++)
            a.push(i);

        std::cout << "Itering: " << std::endl;
        for (it = a.begin(); it != a.end(); it++)
            std::cout << *it << std::endl;

        std::cout << "Reverse_itering: " << std::endl;
        for (rit = a.rbegin(); rit != a.rend(); rit++)
            std::cout << *rit << std::endl;


        std::cout << "***END ITERATORS" << std::endl;
    }
}
