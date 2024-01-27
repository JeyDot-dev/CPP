#ifndef		DOG_HPP
# define	DOG_HPP
#include <iostream>
#include "Animal.hpp"

class	Dog : virtual public Animal
{

public:
	Dog(Dog const & src);
	Dog&	operator=(Dog const& rhs);

	virtual void	makeSound(void)	const;

	Dog(void);
	~Dog(void);

private:

};

#endif
