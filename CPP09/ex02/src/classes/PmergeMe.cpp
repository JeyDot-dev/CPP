#include "PmergeMe.hpp"

//--------------Functions----------------//
//--------------Operators----------------//
PmergeMe&	PmergeMe::operator=(PmergeMe const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
