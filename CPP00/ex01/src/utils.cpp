/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:36:28 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 18:36:46 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.hpp"

void	print_cell(std::string s)
{
	std::string str;
	std::cout << '|';
	std::cout << std::setw(10);
	if (s.length() > 10)
	{
		str = s.substr(0, 9) + '.';
		std::cout << str;
	}
	else
		std::cout << s;
}

clean_case	hash_case(std::string str)
{
	if (str == "ADD")
		return (ADD);
	else if (str == "SEARCH")
		return (SEARCH);
	else if (str == "EXIT")
		return (EXIT);
	else
		return (NONE);
}
