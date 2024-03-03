#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP
#include <iostream>

class	PmergeMe
{

public:
	PmergeMe(PmergeMe const & src);
	PmergeMe&	operator=(PmergeMe const& rhs);

	PmergeMe(void);
	~PmergeMe(void);

private:

};

#endif
