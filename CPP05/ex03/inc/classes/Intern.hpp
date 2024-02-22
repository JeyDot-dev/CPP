#ifndef		INTERN_HPP
# define	INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class	Intern
{

public:
	Intern(Intern const & src);
	Intern&	operator=(Intern const& rhs);

    AForm* makeForm(std::string const& type, std::string const& target) const;

	Intern(void);
	~Intern(void);

private:

};

#endif
