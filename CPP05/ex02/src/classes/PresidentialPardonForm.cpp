#include "PresidentialPardonForm.hpp"

//--------------Functions----------------//
//--------------Operators----------------//
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
