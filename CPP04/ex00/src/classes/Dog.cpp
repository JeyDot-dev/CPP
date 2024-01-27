/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 16:56:05 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

//--------------Functions----------------//
void	Dog::makeSound(void) const
{
	std::cout << type << ": Woof WOOF !!" << std::endl;
}
//--------------Operators----------------//
Dog&	Dog::operator=(Dog const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (DOG)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Copy constructor called (DOG)" << std::endl;
	return ;
}

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default constructor called (DOG)" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called (DOG)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
