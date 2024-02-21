#ifndef		SHRUBBERYCREATIONFORM_HPP
# define	SHRUBBERYCREATIONFORM_HPP
#include    "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);


	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);

private:
	void		actuallyExecute(Bureaucrat const& executor) const;
    std::string const   _target;

};

#endif
