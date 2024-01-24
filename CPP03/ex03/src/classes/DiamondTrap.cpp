/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:54:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/24 20:15:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"

//--------------Functions----------------//
void	DiamondTrap::whoAmI(void)	const
{
	std::cout <<	"Diamond name :" << this->_name <<
					"  Claps name :" << this->ClapTrap::getName() << std::endl;
}

//--------------Operators----------------//
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const&  rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name", _baseHp, _baseEp, _baseAd),
	ScavTrap(),
	FragTrap()
{
	this->_name = name;
	std::cout << "Constructor for " << name << " called (Diamond)" << std::endl;
}
DiamondTrap::DiamondTrap(void) : ClapTrap("Nameless Diamond_clap_name", _baseHp, _baseEp, _baseAd), _name("Nameless Diamond")
{
	std::cout << "Default constructor called (Diamond)" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called (Diamond)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
