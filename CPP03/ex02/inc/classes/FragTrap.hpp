#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP
#include <iostream>
#include <ClapTrap.hpp>

class	FragTrap : public virtual ClapTrap
{

public:
	FragTrap(FragTrap const & src);
	FragTrap(std::string name);

	FragTrap&	operator=(FragTrap const& rhs);

	void	highFivesGuys(void)	const;
	FragTrap(void);
	~FragTrap(void);

private:

};

#endif
