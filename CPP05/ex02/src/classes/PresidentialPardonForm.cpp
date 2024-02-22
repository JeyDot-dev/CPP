#include "PresidentialPardonForm.hpp"

//--------------Functions----------------//
void    PresidentialPardonForm::actuallyExecute() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
//--------------Operators----------------//
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const&  rhs)
{
	if (this != &rhs)
        AForm::operator=(rhs);
	return *this;
}
//--------------Constructors------------//
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
    AForm(src),
    _target(src._target)
{
	std::cout << "Copy constructor called (president)" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
    AForm("PresidentialPardonForm", 25, 5),
    _target(target)
{
	std::cout << "Init constructor called for (president)" << std::endl;
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5),
                                                    _target("def_target")
{
	std::cout << "Default constructor called for (president)" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called (president)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
