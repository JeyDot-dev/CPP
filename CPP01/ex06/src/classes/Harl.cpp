/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:43:29 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/20 18:54:02 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
void	Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<<	std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<<	std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month."
	<<	std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now."
	<<	std::endl;
}

void	Harl::complain(std::string	level)
{
	int			i = 0;
	void		(Harl::*fn[4]) (void)	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	str[4] 					= {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i < 4 && level != str[i])
		i++;
//	if (i > 3)
//		std::cout << "Karen: OMGGGGGG YOU GOTTA ENTER A LEVELLL!!!! ./Harl [DEBUG, INFO, WARNING, ERROR]" << std::endl;
//	for (; i < 4; i++)
//		(this->*fn[i])();
	switch (i)
	{
		case 0:
			(this->*fn[0])();
		case 1:
			(this->*fn[1])();
		case 2:
			(this->*fn[2])();
		case 3:
			(this->*fn[3])();
			break;
		default:
			std::cout << "Karen: OMGGGGGG YOU GOTTA ENTER A LEVELLL!!!! ./Harl [DEBUG, INFO, WARNING, ERROR]" << std::endl;
	}
}

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}
