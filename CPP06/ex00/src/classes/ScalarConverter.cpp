#include "ScalarConverter.hpp"

//--------------Functions----------------//
//--------------Operators----------------//
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (ScalarConverter)" << std::endl;
	return *this;
}
//--------------Constructors------------//
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	std::cout << "Copy constructor called (ScalarConverter)" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called (ScalarConverter)" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called (ScalarConverter)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
