
#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP
#include <iostream>

class	WrongAnimal
{

public:
	WrongAnimal(WrongAnimal const & src);
	WrongAnimal(std::string type);
	WrongAnimal&	operator=(WrongAnimal const& rhs);
	
	std::string		getType(void) const;
	void	makeSound(void)	const;

	WrongAnimal(void);
	virtual ~WrongAnimal(void);
protected:
	std::string	type;
private:

};

#endif
