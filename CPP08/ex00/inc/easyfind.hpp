#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
    public: char const* what() const throw(){return "exception: nb not found";}
};

template <typename T>
typename T::iterator    easyfind(T& container, int to_find)
{
    typename T::iterator end = container.end();
    typename T::iterator found = std::find(container.begin(), end, to_find);
    if (found == end)
        throw(NotFoundException());
    return found;
}
#endif
