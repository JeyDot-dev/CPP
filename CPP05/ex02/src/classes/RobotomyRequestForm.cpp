#include "RobotomyRequestForm.hpp"

//--------------Functions----------------//
//--------------Operators----------------//
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
