#ifndef		CAT_HPP
# define	CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : virtual public Animal
{

public:
	Cat(Cat const & src);
	Cat&	operator=(Cat const& rhs);

	void			addIdea(std::string idea);
	void			makeSound(void)	const;
	void			printIdeas(void)	const;

	Cat(void);
	~Cat(void);

private:
	Brain* const	_brain;

};

#endif
