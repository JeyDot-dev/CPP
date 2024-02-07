/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:58 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/07 14:58:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
void	PhoneBook::print_all(void)	const
{
	int	order = 1;
	int	i = 0;

	print_cell("index");
	print_cell("first name");
	print_cell("last name");
	print_cell("nickname");
	std::cout << '|' << std::endl;
	while (order < 9)
	{
		while (i < 8 && this->contact[i].index != order)
			i++;
		if (this->contact[i].index == order)
			this->contact[i].print_line();
		order++;
		i = 0;
	}
}

void	PhoneBook::search(void)	const
{
	int		i = 0;
	std::string	u_input;

	while (i < 8 && this->contact[i].index < 0)
		i++;
	if (i == 8)
	{
		std::cout << "No contacts in the book yet" << std::endl;
		return;
	}
	this->print_all();
	std::cout << "type index: " << std::endl;
	std::getline(std::cin, u_input);
	if (u_input.length() == 1 && u_input[0] > '0' && u_input[0] < '9')
	{
		i = 0;
		while (i < 8)
		{
			if (this->contact[i].index == u_input[0] - 48)
			{
				this->contact[i].print_contact();
				break ;
			}
			i++;
		}
		if (i == 8)
			std::cout << "contact not found" << std::endl;
	}
	else
		std::cout << "invalid input" << std::endl;
}

void	PhoneBook::add_contact(void)
{
	Contact new_contact;
	int		i = 0;

	new_contact.create();
	while (this->contact[i].index > 0 && i < 8)
		i++;
	new_contact.index = i + 1;
	if (i < 8)
		this->contact[i] = new_contact;
	else
	{
		i = -1;
		while (++i < 8)
			this->contact[i].index -= 1;
		i = 0;
		while (this->contact[i].index != 0)
		{
			i++;
		}
		new_contact.index = 8;
		this->contact[i] = new_contact;
	}
}
//~~~~~~~~~~~~~~~~~~~Utilities and constructors/destructors~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PhoneBook::PhoneBook(void)
{
	std::cout << "++++Created PhoneBook instance" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "----Destroyed PhoneBook instance" << std::endl;
	return ;
}
