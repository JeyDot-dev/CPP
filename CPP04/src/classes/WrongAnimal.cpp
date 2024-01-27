/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:11 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 17:23:11 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongAnimal.hpp"

//--------------Functions----------------//
std::string	WrongAnimal::getType(void) const
{
	return this->type;
}
void	WrongAnimal::makeSound(void) const
{
	std::cout << type << ": I'm an animal.. or am I?" << std::endl;
}
//--------------Operators----------------//
WrongAnimal&	WrongAnimal::operator=(WrongAnimal const&  rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	std::cout << "Assignation operator called (WRONGANIMAL)" << std::endl;
	return *this;
}
//--------------Constructors------------//
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Init type operator called (WRONGANIMAL) for "<< this->type << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src) : type(src.type)
{
	std::cout << "Copy constructor called (WRONGANIMAL)" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "Default constructor called (WRONGANIMAL)" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called (WRONGANIMAL)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
