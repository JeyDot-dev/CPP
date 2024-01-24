#ifndef		DIAMONDTRAP_HPP
# define	DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{

public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & src);
	DiamondTrap&	operator=(DiamondTrap const& rhs);

	void	whoAmI(void) const;


	DiamondTrap(void);
	~DiamondTrap(void);

protected:
	static int const		_baseHp = FragTrap::_baseHp;
	static int const		_baseEp = ScavTrap::_baseEp;
	static int const		_baseAd = FragTrap::_baseAd;

private:
	std::string	_name;

};

#endif
