#ifndef		AMATERIA_HPP
# define	AMATERIA_HPP
#include <iostream>

class	AMateria
{

public:
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
