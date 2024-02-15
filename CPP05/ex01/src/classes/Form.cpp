#include "Form.hpp"
#include "Bureaucrat.hpp"

//--------------Functions----------------//
void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > this->getSignReq())
		throw Form::GradeTooLowException();
	if (this->_is_signed == true)
		std::cout << "Form: " << this->getName() << " already signed." << std::endl;
	else
	{
		std::cout << "Form: " << this->getName() << " has been signed by "
		<< b.getName() << "." << std::endl;
	}
	this->_is_signed = true;
}
std::string const&	Form::getName() const
{
	return this->_name;
}
bool				Form::getIsSigned() const
{
	return this->_is_signed;
}
int					Form::getSignReq() const
{
	return this->_sign_req;
}
int					Form::getExecReq() const
{
	return this->_exec_req;
}
//--------------Operators----------------//
Form&	Form::operator=(Form const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (Form)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Form::Form(Form const &src) :
	_name(src.getName() + "_prime"),
	_is_signed(src.getIsSigned()),
	_sign_req(src.getSignReq()),
	_exec_req(src.getExecReq())
{
	if (this->getSignReq() < 1 || getExecReq() < 1)
		throw Form::GradeTooHighException();
	if (this->getSignReq() > 150 || getExecReq() > 150)
		throw Form::GradeTooLowException();
	std::cout << "Copy constructor called (Form)" << std::endl;
	return ;
}

Form::Form(void) :	_name("Default_form"), _is_signed(false),
					_sign_req(75), _exec_req(75)
{
	std::cout << "Default constructor called (Form)" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Destructor called (Form)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
char const* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low.";
}
char const* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high.";
}
std::ostream& operator<<(std::ostream& o, Form const& rhs)
{
	return	o << "Form: " << rhs.getName() << " | is_signed: " <<
		rhs.getIsSigned() << " | req grade(exec): " <<
		rhs.getExecReq() << " | req grade(sign): " <<
		rhs.getSignReq() << std::endl;
}
