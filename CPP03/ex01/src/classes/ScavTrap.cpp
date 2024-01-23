#include "ScavTrap.hpp"

//--------------Functions----------------//
void	ScavTrap::attack(const std::string& target)
{
	if (this->getHp() < 1 || this->getEp() < 1)
		std::cout << this->getName() << ": Ready for action, but it seems my energy is on a \
coffee break or I'm just feeling a bit ethereal." << std::endl;
	else
	{
		this->setEp(this->getEp() - 1);
		std::cout << this->getName() << 
		": Initiating combat sequence! Brace yourself for an onslaught of awesomeness. " << 
		"(" << this->getName() << " deals \033[31m" << this->getAd() << "\033[0m damage to " <<
		target << ")..." << std::endl;
	}
}
void	ScavTrap::guardGate(void)
{
	std::cout << this->getName() << ": Activating \033[34mGatekeeper\033[0m mode! \
Prepare to face the challenges of my virtual fortress." << std::endl;
}
//--------------Operators----------------//
ScavTrap&	ScavTrap::operator=(ScavTrap const&  rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}
//--------------Constructors------------//
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copy constructor called (Scav)" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name, 100, 50, 20)
{
	std::cout << name << " is born (scav constructor)" << std::endl;
	return ;
}

ScavTrap::ScavTrap(void): ClapTrap("Nameless scav", 100, 50, 20)
{
	std::cout << "Default constructor called (Scav)" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called (Scav)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
