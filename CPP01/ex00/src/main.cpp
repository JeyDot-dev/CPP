/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:15:52 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 16:54:20 by jsousa-a         ###   ########.fr       */
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

	std::cout << "testing zombie in main: " << test->get_name() << std::endl;

	delete test;
	return (0);
}
