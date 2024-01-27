#ifndef		CAT_HPP
# define	CAT_HPP
#include <iostream>
#include "Animal.hpp"

class	Cat : virtual public Animal
{

public:
	Cat(Cat const & src);
	Cat&	operator=(Cat const& rhs);

	virtual void	makeSound(void)	const;

	Cat(void);
	~Cat(void);

private:

};

#endif
