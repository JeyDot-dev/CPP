/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:12:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/31 20:36:12 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"

//--------------Functions----------------//
std::string const&	Character::getName() const
{
	return _name;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "index " << idx <<
		" not in inventory range for materia" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "No spell found for " << this->getName() << " in inventory \
at index " << idx << std::endl;
		return ;
	}
	else
		this->_inventory[idx]->use(target);

}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		if (g_debug)
			std::cout << "equip : Materia error" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
		{
			std::cout << m->getType() <<":"<< m << " already equipped" << std::endl;
			return ;
		}
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			if (g_debug)
			{
				std::cout << this->getName() << ": equipped " <<
					this->_inventory[i]->getType() << std::endl;
			}
			return ;
		}
	}
	if (g_debug)
		std::cout << "equip : Inventory full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		if (g_debug)
			std::cout << "unequip : bad index " << idx << std::endl;
	}
	else if (!this->_inventory[idx])
	{
		if (g_debug)
			std::cout << "unequip : no iteam at index " << idx << std::endl;
	}
	else
	{
		this->_floor[_nbOnFloor] = this->_inventory[idx];
		this->_nbOnFloor++;
		this->_inventory[idx] = NULL;
		if (g_debug)
		{
			std::cout <<	this->getName() << ": unequipped " 			<< 
							this->_floor[this->_nbOnFloor]->getType()	<<
							std::endl;
		}
	}
}
AMateria**	Character::_copyInv(AMateria const* const* inventory)
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
Character&	Character::operator=(Character const&  rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_copyInv(rhs._inventory);
	}
	if (g_debug)
		std::cout << "Assignation operator called (Character)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Character::Character(Character const &src) : _name(src.getName()), _nbOnFloor(0)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	this->_copyInv(src._inventory);
	if (g_debug)
		std::cout << "Copy constructor called (Character)" << std::endl;
	return ;
}

Character::Character(std::string const& name) : _name(name), _nbOnFloor(0)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	if (g_debug)
		std::cout << "Name constructor called (Character)" << std::endl;
	return ;
}
Character::Character(void) : _name("Nameless"), _nbOnFloor(0)
{
	_inventory[0] = NULL;
	_inventory[1] = NULL;
	_inventory[2] = NULL;
	_inventory[3] = NULL;
	if (g_debug)
		std::cout << "Default constructor called (Character)" << std::endl;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < _nbOnFloor; i++)
		delete _floor[i];
	if (g_debug)
		std::cout << "Destructor called (Character)" << std::endl;
	return ;
}
//--------------Non-Member--------------//

