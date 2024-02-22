#ifndef		SHRUBBERYCREATIONFORM_HPP
# define	SHRUBBERYCREATIONFORM_HPP
#include    "AForm.hpp"
#include    <fstream>

class	ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);


	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);

private:
	void		actuallyExecute() const;
    std::string const   _target;

};

#endif
