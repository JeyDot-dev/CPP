/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:08:53 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 20:10:34 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HumanA.hpp"

void	HumanA::equipped_info(void)		const
{
	std::cout << this->_name << " equipped " << this->_weapon.getType() << std::endl;
}

void	HumanA::attack(void)			const
{
	std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weap): _name(name), _weapon(weap)
{
	std::cout << this->_name << " is born!" << std::endl;
	this->equipped_info();
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "Bye: " << this->_name << std::endl;
	return ;
}
