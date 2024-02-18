/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:22:48 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/15 17:22:50 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//--------------Functions----------------//
void	AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > this->getSignReq())
		throw AForm::GradeTooLowException();
	if (this->_is_signed == true)
		std::cout << "AForm: " << this->getName() << " already signed." << std::endl;
	else
	{
		std::cout << "AForm: " << this->getName() << " has been signed by "
		<< b.getName() << "." << std::endl;
	}
	this->_is_signed = true;
}
std::string const&	AForm::getName() const
{
	return this->_name;
}
bool				AForm::getIsSigned() const
{
	return this->_is_signed;
}
int					AForm::getSignReq() const
{
	return this->_sign_req;
}
int					AForm::getExecReq() const
{
	return this->_exec_req;
}
//--------------Operators----------------//
AForm&	AForm::operator=(AForm const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (AForm)" << std::endl;
	return *this;
}
//--------------Constructors------------//
AForm::AForm(AForm const &src) :
	_name(src.getName() + "_prime"),
	_is_signed(src.getIsSigned()),
	_sign_req(src.getSignReq()),
	_exec_req(src.getExecReq())
{
	if (this->getSignReq() < 1 || getExecReq() < 1)
		throw AForm::GradeTooHighException();
	if (this->getSignReq() > 150 || getExecReq() > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Copy constructor called (AForm)" << std::endl;
	return ;
}

AForm::AForm(void) :	_name("Default_form"), _is_signed(false),
					_sign_req(75), _exec_req(75)
{
	std::cout << "Default constructor called (AForm)" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called (AForm)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
char const* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade too low.";
}
char const* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade too high.";
}
std::ostream& operator<<(std::ostream& o, AForm const& rhs)
{
	return	o << "AForm: " << rhs.getName() << " | is_signed: " <<
		rhs.getIsSigned() << " | req grade(exec): " <<
		rhs.getExecReq() << " | req grade(sign): " <<
		rhs.getSignReq() << std::endl;
}
