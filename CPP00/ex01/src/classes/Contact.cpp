/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:50:41 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 18:30:27 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.hpp"

std::string	add_user_input(std::string awaited);

void	Contact::create(void)
{
	this->first_name = add_user_input("first name");
	this->last_name = add_user_input("last name");
	this->nickname = add_user_input("nickname");
	this->phone_number = add_user_input("phone number");
	this->darkest_secret = add_user_input("dark secret");
}

void	Contact::print_line(void)	const
{
	std::string	index(1, this->index + 48);
	print_cell(index);
	print_cell(this->first_name);
	print_cell(this->last_name);
	print_cell(this->nickname);
	std::cout << '|' << std::endl;
}

void	Contact::print_contact(void)	const
{
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "why they go to prison: " << this->darkest_secret << std::endl;
}
//~~~~~~~~~~~~~~~~~~~Utilities and constructors/destructors~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Contact::Contact(void)
{
	this->index = -1;
	std::cout << "++++Created Contact instance" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "----Destroyed Contact instance" << std::endl;
	return ;
}

std::string	add_user_input(std::string awaited)
{
	int		i = 1;
	std::string	str;

	while (i == 1)
	{
		std::cout << "[" << awaited << "]: ";
		std::getline(std::cin, str);
		if (str.empty() || str[0] == '\n' ||
			(!awaited.compare("phone number") && str.find_first_not_of("0123456789") != str.npos))
			std::cout << "/!\\ please enter a " << awaited << std::endl;
		else
			i = 0;
	}
	str[0] = static_cast<unsigned char>(std::toupper(str[0]));
	return (str);
}
