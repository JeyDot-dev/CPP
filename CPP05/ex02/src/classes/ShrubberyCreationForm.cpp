#include "ShrubberyCreationForm.hpp"

//--------------Functions----------------//
//--------------Operators----------------//
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
