#ifndef		CHARACTER_HPP
# define	CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter
{

public:
	Character(Character const & src);
	Character(std::string const& name);
	Character&	operator=(Character const& rhs);

	std::string const&	getName()	const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	Character(void);
	~Character(void);

private:
	AMateria**		_copyInv(AMateria const* const* inventory);

	std::string		_name;
	AMateria*		_inventory[4];
	AMateria*		_floor[66];
	int				_nbOnFloor;

};

#endif
