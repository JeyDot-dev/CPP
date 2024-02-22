#ifndef		ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <ctime>

class	RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);


	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);

private:
	void		actuallyExecute() const;
    std::string const   _target;

};

#endif
