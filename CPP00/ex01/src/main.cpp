/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:08:40 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 18:39:27 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.hpp"

int	main(void)
{
	std::string	u_input;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "menu: ";
		std::getline(std::cin, u_input);
		switch(hash_case(u_input))
		{
			case ADD:
				pb.add_contact();
				break;
			case SEARCH:
				pb.search();
				break;
			case EXIT:
				return (0);
			case NONE:
				std::cout << "usage: ADD, SEARCH or EXIT" << std::endl;
		}
	}
}
