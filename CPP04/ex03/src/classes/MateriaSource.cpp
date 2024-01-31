/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:15:52 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/31 21:00:29 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"

//--------------Functions----------------//
void		MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		if (g_debug)
			std::cout << "learnMateria : Materia error" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m->clone();
			if (g_debug)
				std::cout << "learned: " << this->_inventory[i]->getType() << std::endl;
			delete m;
			return ;
		}
	}
	delete m;
	if (g_debug)
		std::cout << "learnMateria : Inventory full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	if (g_debug)
		std::cout << "\"" << type <<"\" not found in MateriaSource inventory" << std::endl;
	return NULL;
}
AMateria**	MateriaSource::_copyInv(AMateria const* const* inventory)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = inventory[i]->clone();
	}
	return this->_inventory;
}
//--------------Operators----------------//
MateriaSource&	MateriaSource::operator=(MateriaSource const&  rhs)
{
	if (this != &rhs)
	{
		this->_copyInv(rhs._inventory);
	}
	if (g_debug)
		std::cout << "Assignation operator called (MateriaSource)" << std::endl;
	return *this;
}
//--------------Constructors------------//
MateriaSource::MateriaSource(MateriaSource const &src)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	this->_copyInv(src._inventory);
	if (g_debug)
		std::cout << "Copy constructor called (MateriaSource)" << std::endl;
	return ;
}

MateriaSource::MateriaSource(void)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	if (g_debug)
		std::cout << "Default constructor called (MateriaSource)" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete _inventory[i];
	}
	if (g_debug)
		std::cout << "Destructor called (MateriaSource)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
