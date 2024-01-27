/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:56:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 20:42:28 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"

//--------------Functions----------------//
void	Dog::addIdea(std::string idea)
{
	this->_brain->addIdea(idea);
}
void	Dog::makeSound(void) const
{
	std::cout << type << ": Woof WOOF !!" << std::endl;
}
void	Dog::printIdeas(void)	const
{
	for	(int i = 0; i < 99 ; i++)
		std::cout << this->_brain->getIdea(i) << ";" << std::flush;
	std::cout << this->_brain->getIdea(99) << std::endl;
}
//--------------Operators----------------//
Dog&	Dog::operator=(Dog const&  rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*this->_brain = *rhs._brain;
	}
	std::cout << "Assignation operator called (DOG)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Dog::Dog(Dog const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Copy constructor called (DOG)" << std::endl;
	return ;
}

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Default constructor called (DOG)" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor called (DOG)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
