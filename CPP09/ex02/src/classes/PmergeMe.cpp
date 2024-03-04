#include "PmergeMe.hpp"

//--------------Functions----------------//
void    PmergeMe::insertSort(pvector& vec, size_t l, size_t r) const
{
}
void    PmergeMe::insertSort(plist& list, size_t l, size_t r) const
{
    if (list.size() / 2 >= l)
    {
        plist_it    it = list.begin();
        for(size_t i = 0; i < l; i++)
            it++;
    }
    else
    {
        plist_it    it_end = list.end();
        it_end--;
        for (size_t i = 0; i < list.size() - l; i++)
            it_end++;
    }

    
}
template <typename T>
void    PmergeMe::mergeInsertSort(T& cont, size_t l, size_t r) const
{
    if (cont.size() <= 1)
        return;
    if ((cont.size() <= 32 && typeid(T) == typeid(pvector))
            || (cont.size() <= 12 && typeid(T) == typeid(plist)))
        insertSort(cont);
    else
    {
        size_t  m = (l - r) / 2 + l;
        mergeInsertSort(cont, l, m);
        mergeInsertSort(cont, m + 1, r);
        mergeSort(cont, l, m, r);
    }
}
void    PmergeMe::parse(int ac, char** av, pvector& vec) const
{
    (void)ac;
    (void)av;
    (void)vec;
}
void    PmergeMe::parse(int ac, char** av, plist& list) const
{
    (void)ac;
    (void)av;
    (void)list;
}
void    PmergeMe::checkStr(int ac, char** av) const
{
    (void)ac;
    (void)av;
}
bool    PmergeMe::sort(int ac, char** av) const
{
    try{checkStr(ac, av);}
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return false;}
    time_t  timer[2][2];

    time(&(timer[0][0]));
    pvector vec;
    parse(ac, av, vec);
    mergeInsertSort(vec);
    time(&(timer[0][1]));

    time(&(timer[1][0]));
    plist   list;
    parse(ac, av, list);
    mergeInsertSort(list);
    time(&(timer[1][1]));

    printResults(timer, vec, list);
    return true;
}
//--------------Operators----------------//
PmergeMe&	PmergeMe::operator=(PmergeMe const&  rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}
//--------------Constructors------------//
PmergeMe::PmergeMe(PmergeMe const &src)
{
    (void)src;
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}
//--------------Non-Member--------------//
