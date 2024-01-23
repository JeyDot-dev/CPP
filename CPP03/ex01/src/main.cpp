/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:37:08 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/23 16:22:59 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
//			===CLAPS===
	std::cout <<"--clap-t a---" << std::endl;
	ClapTrap a;
	a.attack("Montagnier");
	a.takeDamage(6);
	a.beRepaired(1);
	
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
//			===SCAVS===
	std::cout <<"\n\033[34m--scav-t aa---\033[0m" << std::endl;
	ScavTrap aa;
	aa.attack("Gilbert");
	aa.takeDamage(60);
	aa.beRepaired(1);

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
	std::cout << "\t DESTRUCTORS" << std::endl;
}
