/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:16 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 16:56:18 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

//--------------Functions----------------//
void	WrongCat::makeSound(void) const
{
	std::cout << type << ": Meow..." << std::endl;
}
//--------------Operators----------------//
WrongCat&	WrongCat::operator=(WrongCat const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (WRONGCAT)" << std::endl;
	return *this;
}
//--------------Constructors------------//
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "Copy constructor called (WRONGCAT)" << std::endl;
	return ;
}

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called (WRONGCAT)" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called (WRONGCAT)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
