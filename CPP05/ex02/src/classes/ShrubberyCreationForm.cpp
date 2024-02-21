#include "ShrubberyCreationForm.hpp"

//--------------Functions----------------//
void    ShrubberyCreationForm::actuallyExecute(Bureaucrat const& executor) const
{
    (void) executor;
    std::cout << *this << std::endl;
}
//--------------Operators----------------//
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const&  rhs)
{
	if (this != &rhs)
        AForm::operator=(rhs);
	return *this;
}
//--------------Constructors------------//
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
    AForm(src),
    _target(src._target)
{
	std::cout << "Copy constructor called (shrub)" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{
	std::cout << "Init constructor called for (shrub)" << std::endl;
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137),
                                                    _target("def_target")
{
	std::cout << "Default constructor called for (shrub)" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called (shrub)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
