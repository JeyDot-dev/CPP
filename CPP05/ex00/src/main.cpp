/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:40:16 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/04 16:30:41 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("Wilson", 30);
	Bureaucrat*	b;

	std::cout << a << "\n" << std::endl;

	try
	{
		b = new Bureaucrat("Winston", 1);
		Bureaucrat	c = Bureaucrat("Weebson", 150);
		std::cout << c << std::endl;
		c.decGrade();						//Exception
		std::cout << "WONT REACH" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}

	try
	{
		a = *b;
		Bureaucrat	c("Weebson", 151);		//Exception
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}

//				a = Wilson, b = Winston, c = Wilson(copy init)
	a.decGrade();
	Bureaucrat	c(a);
	c.decGrade();

	std::cout << a << std::endl;
	std::cout << *b << std::endl;
	std::cout << c << std::endl;
	delete b;
}
