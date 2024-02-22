#include "ShrubberyCreationForm.hpp"
#include <fstream>

//--------------Functions----------------//
void    ShrubberyCreationForm::actuallyExecute() const
{
    std::ofstream of;
    of.open((this->_target + "_shrubbery").c_str(), std::ofstream::trunc);
    if (of.is_open())
    {
        of << "       _-_\
\n    /~~   ~~\\\
\n /~~         ~~\\\
\n{               }\
\n \\  _-     -_  /\
\n   ~  \\\\ //  ~\
\n_- -   | | _- _\
\n  _ -  | |   -_\
\n      // \\\\\
";
    std::cout << "Shrubbery success at " << this->_target << "_shrubbery." << std::endl;
    of.close();
    }
    else
        std::cout << "Failed to open " << this->_target << "_shrubbery." << std::endl;
}
//--------------Operators----------------//
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const&  rhs)
{
	if (this != &rhs)
        AForm::operator=(rhs);
	return *this;
}
//--------------Constructors------------//
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
    AForm(src),
    _target(src._target)
{
	std::cout << "Copy constructor called (shrub)" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{
	std::cout << "Init constructor called for (shrub)" << std::endl;
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137),
                                                    _target("def_target")
{
	std::cout << "Default constructor called for (shrub)" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called (shrub)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
