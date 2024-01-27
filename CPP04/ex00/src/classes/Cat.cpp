/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:07 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 16:56:09 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

//--------------Functions----------------//
void	Cat::makeSound(void) const
{
	std::cout << type << ": Meow..." << std::endl;
}
//--------------Operators----------------//
Cat&	Cat::operator=(Cat const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called (CAT)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Copy constructor called (CAT)" << std::endl;
	return ;
}

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default constructor called (CAT)" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called (CAT)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
