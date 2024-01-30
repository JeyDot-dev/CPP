/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:08 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/29 20:12:31 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"

//--------------Functions----------------//
std::string const& getType(void) const
{
	return this->type;
}
void		use(ICharacter& target)
{
	std::cout << "* makes weird symbols with his \
hands and suddenly shouts \"That's my NINDO!!\".. * (no effect)" << std::endl;
}
//--------------Operators----------------//
AMateria&	AMateria::operator=(AMateria const&  rhs)
{
	if (this != &rhs)
	{
	}
	std::cout << "Assignation operator called (AMateria)" << std::endl;
	return *this;
}
//--------------Constructors------------//
AMateria::AMateria(std::string const& new_type) : type(new_type)
{
	std::cout << "Assignation constructor called (AMateria)" << std::endl;
}
AMateria::AMateria(AMateria const &src)
{
	std::cout << "Copy constructor called (AMateria)" << std::endl;
	return ;
}

AMateria::AMateria(void) : type("undefined")
{
	std::cout << "Default constructor called (AMateria)" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor called (AMateria)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
