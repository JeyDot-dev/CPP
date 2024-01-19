/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:25:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:23:06 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"


std::string	Zombie::get_name(void)	const
{
	return this->_name;
}

void		Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)	const
{
	std::cout << this->z_index << " ";
	std::cout <<  this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string	name) : _name(name)
{
	Zombie::instances++;
	this->z_index = instances;
	this->announce();
}

Zombie::Zombie(void)
{
	Zombie::instances++;
	this->z_index = instances;
	return ;
}
Zombie::~Zombie(void)
{
	std::cout << this->z_index << " ";
	std::cout << this->get_name() << " died.. again..." << std::endl;
	return ;
}

int	Zombie::instances = 0;
