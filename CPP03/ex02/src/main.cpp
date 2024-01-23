/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:37:08 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/23 19:48:13 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	test_energy(ClapTrap& trap, std::string name, int energy)
{
	std::string	user_a;
	std::cout << "---\n|Would you like to test the energy of a " << name << "?" <<
	"(" << energy * 2 << " lines) y\\n : " << std::endl;
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

	press_a_key("Claps");
//			===CLAPS===
	std::cout <<"--clap-t a---" << std::endl;
	ClapTrap a;
	a.attack("Montagnier");
	a.takeDamage(6);
	test_energy(a, "clap-trap", 10); // Energy test
	a.attack("Montagnier");

	std::cout <<"\n--clap-t b---" << std::endl;
	ClapTrap b(a);
	b.attack("Gilbert");
	b.takeDamage(1);
	b.takeDamage(4);
	b.attack("Tomb shrimp");
	b.beRepaired(1);

	std::cout <<"\n--clap-t c---" << std::endl;
	ClapTrap c("Link");
	c.attack("Gilbert");
	c.takeDamage(1);
	c.beRepaired(1);

	press_a_key("Scavs");
//			===SCAVS===
	std::cout <<"\n\033[34m--scav-t aa---\033[0m" << std::endl;
	ScavTrap aa;
	aa.attack("Gilbert");
	aa.takeDamage(60);
	aa.beRepaired(1);
	test_energy(aa, "scav-trap", 50); // Energy test
	aa.attack("Gilbert");

	std::cout <<"\n\033[34m--scav-t bb---\033[0m" << std::endl;
	ScavTrap bb(aa);
	bb.attack("Patriccio");
	bb.takeDamage(29);
	bb.takeDamage(12);
	bb.attack("Tomb shrimp");
	bb.beRepaired(1);

	std::cout <<"\n\033[34m--clap-t cc---\033[0m" << std::endl;
	ScavTrap cc("Bojack");
	cc.guardGate();
	cc.attack("Michelangelo");
	cc.takeDamage(1);
	cc.beRepaired(1);

	std::cout <<"\n\033[34m--clap-t dd---\033[0m" << std::endl;
	ClapTrap*	dd_p;
	ScavTrap dd("Pointed");
	dd_p = &dd;
	dd_p->takeDamage(50);
	dd_p->takeDamage(50);

	press_a_key("Frags");
//			===FRAGS===
	std::cout <<"\n\033[31m--clap-t aaa---\033[0m" << std::endl;
	FragTrap aaa;
	aaa.attack("Ripool");
	aaa.takeDamage(60);
	aaa.beRepaired(1);
	test_energy(aaa, "frag-trap", 100); // Energy test
	aaa.attack("Ripool");

	std::cout <<"\n\033[31m--clap-t bbb---\033[0m" << std::endl;
	FragTrap bbb(aaa);
	bbb.attack("Patricia");
	bbb.takeDamage(29);
	bbb.takeDamage(12);
	bbb.attack("Tomb shrimp");
	bbb.beRepaired(1);

	std::cout <<"\n\033[31m--clap-t ccc---\033[0m" << std::endl;
	FragTrap ccc("Horseman");
	ccc.highFivesGuys();
	ccc.attack("Mijelle Ange");
	ccc.takeDamage(1);
	ccc.beRepaired(1);

	std::cout <<"\n\033[31m--clap-t ddd---\033[0m" << std::endl;
	ClapTrap*	ddd_p;
	FragTrap ddd("DDD*");
	ddd_p = &ddd;
	ddd_p->takeDamage(50);
	ddd_p->takeDamage(50);

	std::cout << "\t DESTRUCTORS" << std::endl;
}
