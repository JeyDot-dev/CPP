/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:58:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 21:01:53 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"

//--------------Functions----------------//
std::string	Brain::getIdea(int	i) const
{
	return this->_ideas[i];
}

void	Brain::addIdea(std::string idea)
{
	this->_ideas[this->_number_of_ideas] = idea;
	this->_number_of_ideas++;
}

int		Brain::howManyIdeas(void)	const
{
	return Brain::_number_of_ideas;
}
//--------------Operators----------------//
Brain&	Brain::operator=(Brain const&  rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
		this->_number_of_ideas = rhs._number_of_ideas;
	}
	std::cout << "Assignation operator called (BRAIN)" << std::endl;
	return *this;
}
//--------------Constructors------------//
Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "Copy constructor called (BRAIN)" << std::endl;
	return ;
}

Brain::Brain(void) : _number_of_ideas(0)
{
	std::cout << "Default constructor called (BRAIN)" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Destructor called (BRAIN)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
