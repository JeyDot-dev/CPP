/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:23:37 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/31 20:36:48 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "g_debug.hpp"

bool g_debug = false;
void	subject_tests(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
void	more_tests(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	Character*	john = new Character("John");
	AMateria*	ice1 = src->createMateria("ice");
	Ice*		ice2 = new Ice();
	Ice*		ice3 = new Ice(*ice2);
	AMateria*	cure1 = src->createMateria("cure");

	john->equip(ice1);
	john->equip(ice1);
	john->equip(ice2);
	john->equip(cure1);

	Character* cena = new Character(*john);
	std::cout << "&cena:&cohn | " << cena << ":" << john << std::endl;
	cena->use(0, *john);
	cena->use(1, *cena);
	cena->use(2, *john);
	cena->use(3, *cena);
	john->equip(ice3);
	john->use(3, *cena);
	cena->use(3, *john);

	delete john;
	delete cena;
	delete src;
}
int main(int ac, char** av)
{
	(void) av;
	if (ac > 1)
		g_debug = true;
	std::cout << "\t*****Tests from the subject*****" << std::endl;
	subject_tests();
	std::cout << "\n\t****Some more tests*****" << std::endl;
	more_tests();
	return 0;
}

