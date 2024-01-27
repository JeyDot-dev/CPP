
#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP
#include <iostream>

class	Animal
{

public:
	Animal(Animal const& src);
	Animal(std::string const type);
	Animal&	operator=(Animal const& rhs);
	
	std::string		getType(void) const;
	virtual void	makeSound(void)	const = 0;

	Animal(void);
	virtual ~Animal(void);
protected:
	std::string	type;
private:

};

#endif
