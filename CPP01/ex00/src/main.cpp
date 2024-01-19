/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:15:52 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:05:32 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name);
void	randomChump( std::string name);

int	main(void)
{
	Zombie*	test;

	test = newZombie("Michael J.");
	randomChump("Jerry S.");

	std::cout << "testing zombie in main: ";
	test->announce();

	delete test;
	return (0);
}
