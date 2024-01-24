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
	std::string		getName(void) const;
	int				getHp(void) const;
	int				getAd(void) const;
	void			setHp(int const hp);
	void			setEp(int const ep);
	void			setAd(int const ad);


	~ClapTrap(void);
	ClapTrap(void);

protected:
	static int const			_baseHp = 10;
	static int const			_baseEp = 10;
	static int const			_baseAd = 0;

	ClapTrap(std::string name, int hp, int ep, int ad);


private:
	std::string	const	_name;
	int					_hp;
	int					_ep;
	int					_ad;
};

#endif
