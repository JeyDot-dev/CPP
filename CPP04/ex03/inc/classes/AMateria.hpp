#ifndef		AMATERIA_HPP
# define	AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "g_debug.hpp"

class	AMateria
{

public:
	AMateria(std::string const& type);
	AMateria(AMateria const & src);
	AMateria&	operator=(AMateria const& rhs);

	std::string const & getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	AMateria(void);
	virtual ~AMateria(void);
protected:
	std::string	type;

private:

};

#endif
