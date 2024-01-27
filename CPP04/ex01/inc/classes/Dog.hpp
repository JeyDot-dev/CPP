#ifndef		DOG_HPP
# define	DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{

public:
	Dog(Dog const & src);
	Dog&	operator=(Dog const& rhs);

	void	makeSound(void)		const;
	void	addIdea(std::string idea);
	void	printIdeas(void)	const;

	Dog(void);
	~Dog(void);

private:
	Brain* const	_brain;

};

#endif
