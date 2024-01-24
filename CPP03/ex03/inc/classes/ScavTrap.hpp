#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
{

public:
	ScavTrap(ScavTrap const & src);
	ScavTrap(std::string const name);

	virtual void	attack(const std::string& target);
	void	guardGate(void);

	ScavTrap&	operator=(ScavTrap const& rhs);


	ScavTrap(void);
	~ScavTrap(void);

protected:
	static int const			_baseHp = 100;
	static int const			_baseEp = 50;
	static int const			_baseAd = 20;

private:

};

#endif
