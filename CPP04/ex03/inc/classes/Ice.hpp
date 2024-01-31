#ifndef		ICE_HPP
# define	ICE_HPP
#include <iostream>
#include "AMateria.hpp"

class	Ice : public AMateria
{

public:

	Ice(Ice const & src);
	Ice&	operator=(Ice const& rhs);

	Ice*	clone() const;
	void	use(ICharacter& target);

	Ice(void);
	~Ice(void);

private:

};

#endif
