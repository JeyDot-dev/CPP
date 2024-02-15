/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:42:59 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/15 16:14:00 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

//--------------Functions----------------//
//FINISH THIS FUNCTIOOOOOOOOOOOOOOOOOONNNNN!!!!!!!!!!!!!!!
void				Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout	<< *this << ", grade required for "<< f.getName() << ": "
					<< f.getSignReq() << ". (Bureaucrat's grade too low)" << std::endl; 
	}
}
std::string const&	Bureaucrat::getName() const
{
	return this->_name;
}
int Bureaucrat::getGrade() const
{
	return this->_grade;
}
void	Bureaucrat::decGrade()
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}
void	Bureaucrat::incGrade()
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
//--------------Operators----------------//
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const&  rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	std::cout << "Assignation operator called (bureaucrat)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy constructor called (bureaucrat)" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "constructor called (bureaucrat)" << std::endl;
}

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(75)
{
	std::cout << "Default constructor called (bureaucrat)" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->getName() << ": Destructor called (bureaucrat)" << std::endl;
	return ;
}
//--------------Exceptions------------//
char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Grade is too high";
}
char const*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Grade is too low";
}
//--------------Non-Member--------------//
std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs)
{
	return o << rhs.getName() << ", grade " << rhs.getGrade();
}
