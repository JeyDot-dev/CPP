/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:07 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 20:42:41 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

//--------------Functions----------------//
void	Cat::addIdea(std::string idea)
{
	this->_brain->addIdea(idea);
}
void	Cat::printIdeas(void)	const
{
	for	(int i = 0; i < 99 ; i++)
		std::cout << this->_brain->getIdea(i) << ";" << std::flush;
	std::cout << this->_brain->getIdea(99) << std::endl;
}
void	Cat::makeSound(void) const
{
	std::cout << type << ": Meow..." << std::endl;
}
//--------------Operators----------------//
Cat&	Cat::operator=(Cat const&  rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->_brain = *rhs._brain;
	}
	std::cout << "Assignation operator called (CAT)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Copy constructor called (CAT)" << std::endl;
	return ;
}

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Default constructor called (CAT)" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Destructor called (CAT)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
