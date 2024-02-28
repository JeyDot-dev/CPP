#include "Array.hpp"
#include <iostream>

//--------------Functions----------------//
//--------------Operators----------------//
template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (array)" << std::endl;
	return *this;
}
//--------------Constructors------------//
template <typename T>
Array<T>::Array(Array<T> const &src)
{
	*this = src;
	std::cout << "Copy constructor called (array)" << std::endl;
	return ;
}

template <typename T>
Array<T>::Array(void)
{
	std::cout << "Default constructor called (array)" << std::endl;
	return ;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Destructor called (array)" << std::endl;
	return ;
}
template <typename T>
char const* Array<T>::OutOfBoundsException::what() const throw()
{
    return "exception: You should segfault lel";
}
