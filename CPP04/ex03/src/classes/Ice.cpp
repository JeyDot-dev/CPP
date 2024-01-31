/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:25:21 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/31 20:00:23 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"

//--------------Functions----------------//
Ice*	Ice::clone(void)	const
{
	return new Ice();
}
void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
//--------------Operators----------------//
Ice&	Ice::operator=(Ice const&  rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	if (g_debug)
		std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
	if (g_debug)
		std::cout << "Copy constructor called" << std::endl;
	return ;
}

Ice::Ice(void) : AMateria("ice")
{
	if (g_debug)
		std::cout << "Default constructor called" << std::endl;
	return ;
}

Ice::~Ice(void)
{
	if (g_debug)
		std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
