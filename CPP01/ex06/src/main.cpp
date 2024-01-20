/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:22:30 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/20 18:32:10 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	karen;
	if (ac != 2)
	{
		std::cout << "Karen: OMG YOU GOTTA ENTER A LEVEL... ./Harl [DEBUG, INFO, WARNING, ERROR]"
		<<	std::endl;
		return (1);
	}
	karen.complain(av[1]);
	return (0);
}
