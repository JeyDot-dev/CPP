#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat : virtual public WrongAnimal
{

public:
	WrongCat(WrongCat const & src);
	WrongCat&	operator=(WrongCat const& rhs);

	void	makeSound(void)	const;

	WrongCat(void);
	~WrongCat(void);

private:

};

#endif
