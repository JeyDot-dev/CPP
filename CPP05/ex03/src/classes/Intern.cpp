#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//--------------Functions----------------//
AForm* Intern::makeForm(std::string const& type, std::string const& target) const
{
    int i = 0;
    std::string to_create[3] = {"shrubbery", "robotomy", "presidential"};
    while (i < 3 && type != to_create[i])
        i++;
    switch(i)
    {
        case 0:
            return (new ShrubberyCreationForm(target));
        case 1:
            return (new RobotomyRequestForm(target));
        case 2:
            return (new PresidentialPardonForm(target));
        default:
            std::cout << type << " is not a valid form." << std::endl;
    }
	throw(std::exception());
    return NULL;
}
//--------------Operators----------------//
Intern&	Intern::operator=(Intern const&  rhs)
{
	if (this != &rhs)
	{
	}
	std::cout << "Assignation operator called (intern)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Intern::Intern(Intern const &src)
{
    (void)src;
	std::cout << "Copy constructor called (intern)" << std::endl;
	return ;
}

Intern::Intern(void)
{
	std::cout << "Default constructor called (intern)" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Destructor called (intern)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
