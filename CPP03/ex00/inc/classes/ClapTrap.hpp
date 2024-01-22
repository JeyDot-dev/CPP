#ifndef		CLAPTRAPCLAPTRAP_HPP
# define	CLAPTRAPCLAPTRAP_HPP
#include <iostream>

class	ClapTrap
{

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	ClapTrap&	operator=(ClapTrap const& rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	~ClapTrap(void);
	ClapTrap(void);

private:
	std::string	const	_name;
	int					_hp;
	int					_ep;
	int					_ad;
};

#endif
