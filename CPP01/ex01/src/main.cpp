/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:15:52 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:21:48 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int			i = 0;
	int			N = 12;
	Zombie*		test = zombieHorde(N, "Margerite");

	if (!test)
		return (1);
	while (i < N)
		test[i++].announce();

	delete [] test;
	return (0);
}
