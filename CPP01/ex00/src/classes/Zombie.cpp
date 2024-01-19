/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:25:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:03:25 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

Zombie::Zombie(std::string	name) : _name(name)
{
	this->announce();
}

std::string	Zombie::get_name(void)	const
{
	return this->_name;
}

Zombie::~Zombie(void)
{
	std::cout << this->get_name() << " died.. again..." << std::endl;
}

void	Zombie::announce(void)	const
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
