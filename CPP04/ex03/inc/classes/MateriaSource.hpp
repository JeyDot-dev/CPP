#ifndef		MATERIASOURCE_HPP
# define	MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{

public:
	MateriaSource(MateriaSource const & src);
	MateriaSource&	operator=(MateriaSource const& rhs);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const& type);

	MateriaSource(void);
	~MateriaSource(void);

private:
	AMateria**		_copyInv(AMateria const* const* inventory);
	AMateria*		_inventory[4];

};

#endif
