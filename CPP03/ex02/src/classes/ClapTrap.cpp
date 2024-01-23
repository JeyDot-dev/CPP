/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:34:58 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/23 18:38:33 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//--------------Functions----------------//
std::string	ClapTrap::getName(void) const
{
	return this->_name;
}
int		ClapTrap::getHp(void) const
{
	return this->_hp;
}
int		ClapTrap::getEp(void) const
{
	return this->_ep;
}
int		ClapTrap::getAd(void) const
{
	return this->_ad;
}
void	ClapTrap::setEp(const int value)
{
	this->_ep = value;
}
void	ClapTrap::setHp(int const hp)
{
	this->_hp = hp;
}
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp < 1 || this->_ep < 1)
		std::cout << this->_name << ": I'm ready to attack, but it seems I'm either out of energy\
 or playing the ghost role. Maybe next time!" << std::endl;
	else
	{
		this->_ep--;
		std::cout << this->_name << 
		": Get ready for the awesomeness! Pew pew pew... " << 
		"(" << this->_name << " deals \033[31m" << this->_ad << "\033[0m damage to " <<
		target << ")..." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp < 1)
	{
		std::cout << this->_name << ": Taking more damage won't help! I'm already\
 enjoying the afterlife in bits and bytes." << std::endl;
 		return ;
	}
 	if (this->_hp - amount <= 0)
	{
		this->_hp = 0;
		std::cout << this->_name << ": Oh snap! I've reached the respawn \
point in the sky. Tell my code I loved it! (takes \033[31m" << amount << "\033[0m dmg and....dies...)" << 
		std::endl;
		return ;
	}
	this->_hp -= amount;
	if (amount > 20)
		std::cout << this->_name << ": Ow! That was painful! I need a virtual band-aid \
and a hug. Who programmed this opponent, a sadist? " << "(takes \033[31m" << amount <<
"\033[0m damage, HP falls to \033[31m" << this->_hp << "\033[0m...)" << std::endl;
	else
	{
		std::cout << this->_name << ": Just a scratch! I've been through worse. Is that all you got? Bring it on!" <<
		"(takes " << amount << " damage, HP falls to \033[31m" << this->_hp << "\033[0m...)" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp < 1)
	{
		std::cout << this->_name << ": Attempting to repair, but I'm already \
pushing up virtual daisies. Zombies have better chances!" << std::endl;
	}
	else if (this->_ep < 1)
		std::cout << this->_name << ": Trying to repair, but I'm running on empty! \
Someone toss me an energy drink, please!" << std::endl;
	else
	{
		this->_hp += amount;
		this->_ep--;
		std::cout << this->_name << 
		": Repairing myself! Added \033[32m" << amount << 
		"\033[0m HP. I'm practically a virtual doctor! (current HP \033[31m" << this->_hp << "\033[0m)" << std::endl;

	}
}
//--------------Operators----------------//
ClapTrap&	ClapTrap::operator=(ClapTrap const&  rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_ad = rhs._ad;
		this->_ep = rhs._ep;
	}
	return *this;
}
//--------------Constructors------------//
ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << name << " is born (clap constructor)" << std::endl;
	return ;
}
ClapTrap::ClapTrap(std::string name, int const hp, int const ep, int const ad): _name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << name << " is born (clap constructor)" << std::endl;
	return ;
}
ClapTrap::ClapTrap(ClapTrap const &src): _name(src._name)
{
	std::cout << "Copy (clap constructor)" << std::endl;
	*this = src;
	return ;
}
ClapTrap::ClapTrap(void): _name("Nameless"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Beware..The Nameless..(Clap's Default constructor called)" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for: " << this->_name << " (clap)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
