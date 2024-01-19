/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:47:51 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 20:11:17 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"

void	Weapon::setType(std::string type)
{
	std::cout << this->_type << " evolved to...." << type << std::endl;
	this->_type = type;
}

std::string	Weapon::getType(void)	const
{
	return this->_type;
}

Weapon::Weapon(std::string type): _type(type)
{
	return ;
}

Weapon::Weapon(void)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}
