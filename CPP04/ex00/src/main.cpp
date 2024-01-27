/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:42:18 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/27 17:46:51 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	subject_tests(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}
void	wrong_subject_tests(void)
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
}

int	main(void)
{
	std::cout << "\t----Subject Tests----" << std::endl;
	subject_tests();
	std::cout << "\n\t----WrongSubject Tests----" << std::endl;
	wrong_subject_tests();
	std::cout << "\n\t----Some More WrongTests----" << std::endl;
	const WrongCat	poor_kitty = WrongCat();
	const WrongAnimal* const W_an = &poor_kitty;

	W_an->makeSound();
	poor_kitty.makeSound();
	poor_kitty.WrongAnimal::makeSound();

	std::cout << "\n\t----Some More Tests----" << std::endl;
	Animal*	const pcat = new Cat();
	Animal*	const pcat2 = new Animal(*pcat);
	Animal*	const panimal = new Animal();
	Animal*	const pdog	= new Dog();
	
	pcat->makeSound();
	pcat2->makeSound();
	panimal->makeSound();
	pdog->makeSound();
	*panimal = *pdog;
	panimal->makeSound();
	delete pcat;
	delete pcat2;
	delete panimal;
	delete pdog;
	std::cout << "\n\t----Annnnd More...----" << std::endl;
	Cat		kitty = Cat();
	Animal	animol = Cat(kitty);
	Dog		doggo = Dog();

	kitty.makeSound();
	animol.makeSound();
	doggo.makeSound();
	animol = doggo;
	animol.makeSound();
}
