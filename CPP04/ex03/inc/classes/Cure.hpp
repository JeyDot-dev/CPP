#ifndef		CURE_HPP
# define	CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class	Cure : public AMateria
{

public:
	Cure(Cure const & src);
	Cure&	operator=(Cure const& rhs);

	Cure*		clone() const;
	void		use(ICharacter& target);

	Cure(void);
	~Cure(void);

private:

};

#endif
