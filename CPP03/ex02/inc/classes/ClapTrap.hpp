#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP
#include <iostream>

class	ClapTrap
{

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	ClapTrap&	operator=(ClapTrap const& rhs);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	int				getEp(void) const;

	~ClapTrap(void);
	ClapTrap(void);

protected:

	ClapTrap(std::string name, int hp, int ep, int ad);

	std::string		getName(void) const;
	int				getHp(void) const;
	int				getAd(void) const;
	void			setHp(int const hp);
	void			setEp(int const hp);

private:
	std::string	const	_name;
	int					_hp;
	int					_ep;
	int					_ad;
};

#endif
