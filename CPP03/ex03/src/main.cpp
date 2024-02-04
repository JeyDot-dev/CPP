/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:37:08 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/02 18:27:13 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdio>

void	press_a_key(std::string name)
{
	std::cout << "(press Enter to test " << name << ".)" << std::endl;
	while (std::cin.peek() == EOF){
	}
	std::cin.ignore();
}
void	test_energy(ClapTrap& trap, int energy)
{
	std::string	user_a;
	std::cout << " ---\n>Would you like to test the energy of " << trap.getName() << "?" <<
	"(" << energy * 2 << " lines) y\\n : " << std::flush;
	std::getline(std::cin, user_a);
	if (user_a == "y")
	{
		for (int i = 0; i < energy; i++)
		{
			std::cout << "#" << i << ": " << std::flush;
			trap.beRepaired(1);
			std::cout << "--remaining energy :\033[33m" << trap.getEp() << "\033[0m.." << std::endl;
		}
	}
}

int	main(void)
{
	std::string user_a;
	
	std::cout <<"--Edmond---" << std::endl;
	DiamondTrap	a("Edmond");
	a.attack("Montagnier");
	a.takeDamage(6);
	test_energy(a, 50); // Energy test

	std::cout <<"\n--Edmond2---" << std::endl;
	DiamondTrap b(a);
	b.whoAmI();
	b.highFivesGuys();
	b.guardGate();
	b.attack("Gilbert");
	b.takeDamage(1);
	b.takeDamage(4);
	b.attack("Tomb shrimp");
	b.beRepaired(1);

	std::cout <<"\n--Nameless = Edmond---" << std::endl;
	DiamondTrap c;
	c.attack("Gilbert");
	c.takeDamage(1);
	c.beRepaired(1);
	std::cout << "****Copying pierre to Nameless" << std::endl;
	c = b;
	c.attack("Gilbert");
	c.takeDamage(1);

	std::cout << "\t DESTRUCTORS" << std::endl;
}
