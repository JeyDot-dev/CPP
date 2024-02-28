#ifndef TMAIN_HPP
# define TMAIN_HPP
#include <cstddef>

template <typename T>
void    iter(T* a, size_t size, void (*f) (T&))
{
    for (size_t i = 0; i < size ; i++)
        f(a[i]);
}

template <typename T, size_t N> //Cooler version IMO v
void    iter2(T (&a)[N], void (*f) (T&))
{
    for (size_t i = 0; i < N ; i++)
        f(a[i]);
}
#endif
