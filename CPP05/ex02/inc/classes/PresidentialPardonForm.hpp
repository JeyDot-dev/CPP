#ifndef		PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);


	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);

private:
	void		actuallyExecute() const;
    std::string const   _target;

};

#endif
