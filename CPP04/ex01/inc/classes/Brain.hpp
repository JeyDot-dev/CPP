#ifndef		BRAIN_HPP
# define	BRAIN_HPP
#include <iostream>

class	Brain
{

public:
	Brain(Brain const & src);
	Brain&	operator=(Brain const& rhs);

	void		addIdea(std::string idea);
	std::string	getIdea(int i) const;
	int			howManyIdeas(void) const;

	Brain(void);
	~Brain(void);
protected:
private:
	int			_number_of_ideas;
	std::string	_ideas[100];

};

#endif
