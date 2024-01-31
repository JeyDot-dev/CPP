/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:25:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/31 20:00:08 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"

//--------------Functions----------------//
Cure*	Cure::clone(void)	const
{
	return new Cure();
}
void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
//--------------Operators----------------//
Cure&	Cure::operator=(Cure const&  rhs)
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
Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
	if (g_debug)
		std::cout << "Copy constructor called" << std::endl;
	return ;
}

Cure::Cure(void) : AMateria("cure")
{
	if (g_debug)
		std::cout << "Default constructor called" << std::endl;
	return ;
}

Cure::~Cure(void)
{
	if (g_debug)
		std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
