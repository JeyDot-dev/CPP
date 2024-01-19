/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:14:48 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 20:10:18 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanB.hpp"

void	HumanB::attack(void)			const
{
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void	HumanB::equipped_info(void)		const
{
	std::cout << this->_name << " equipped " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon&	weap)
{
	this->_weapon = &weap;
	this->equipped_info();
}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << name << " is born!" << std::endl;
	return ;
}

HumanB::HumanB(void): _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "Bye: " << this->_name << std::endl;
	return ;
}
