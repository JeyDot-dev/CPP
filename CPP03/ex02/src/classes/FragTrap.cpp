#include "FragTrap.hpp"

//--------------Functions----------------//
void		FragTrap::highFivesGuys(void) const
{
	std::cout << this->getName() << ": Hey there, awesome human! \
Feeling the positive vibes today? How about a virtual \033[31mhigh five\033[0m?" << std::endl;
}
//--------------Operators----------------//
FragTrap&	FragTrap::operator=(FragTrap const&  rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}
//--------------Constructors------------//
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called (Frag)" << std::endl;
	return ;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << name << " is born (Frag constructor)" << std::endl;
}
FragTrap::FragTrap(void) : ClapTrap("Nameless Frag", 100, 100, 30)
{
	std::cout << "Default constructor called (Frag)" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called (Frag)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
