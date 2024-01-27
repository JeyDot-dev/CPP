/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:55:40 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 21:09:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//--------------Functions----------------//
std::string	Animal::getType(void) const
{
	return this->type;
}
//--------------Operators----------------//
Animal&	Animal::operator=(Animal const&  rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type + "?";
	}
	std::cout << "Assignation operator called (ANIMAL)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Animal::Animal(std::string type) : type(type)
{
	std::cout << "Init type operator called (ANIMAL) for "<< this->type << std::endl;
}
Animal::Animal(Animal const &src) : type(src.type + "?")
{
	std::cout << "Copy constructor called (ANIMAL)" << std::endl;
	return ;
}

Animal::Animal(void) : type("Animal")
{
	std::cout << "Default constructor called (ANIMAL)" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called (ANIMAL)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
