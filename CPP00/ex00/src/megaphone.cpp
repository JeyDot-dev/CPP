/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:10:52 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/17 18:48:31 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	std::string	output;

	i = 1;
	if (ac <= 1 )
		output += "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < ac)
	{

		j = 0;
		if (i > 1 && av[i][0])
			output += ' ';
		while (av[i][j])
			output += static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j++])));
		i++;
	}
	std::cout << output << std::endl;
	return (0);
}
