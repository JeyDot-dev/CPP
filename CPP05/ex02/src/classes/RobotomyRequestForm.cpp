#include "RobotomyRequestForm.hpp"

//--------------Functions----------------//
void    RobotomyRequestForm::actuallyExecute() const
{
    if (clock() % 2)
        std::cout << this->_target << " Has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomization failed." << std::endl;
}
//--------------Operators----------------//
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const&  rhs)
{
	if (this != &rhs)
        AForm::operator=(rhs);
	return *this;
}
//--------------Constructors------------//
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
    AForm(src),
    _target(src._target)
{
	std::cout << "Copy constructor called (robot)" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
    AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
	std::cout << "Init constructor called for (robot)" << std::endl;
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45),
                                                    _target("def_target")
{
	std::cout << "Default constructor called for (robot)" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called (robot)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
