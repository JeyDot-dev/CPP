/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:40:16 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/15 17:20:38 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat	a("Wilson", 30);
	AForm		p_form;

	std::cout << "\n" << a << "\n" << p_form << std::endl;

	try
	{
		a.signForm(p_form);
		std::cout << p_form << std::endl;
		a = Bureaucrat("Wilson_nul", 120);
		a.signForm(p_form);
		std::cout << p_form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "\n"<<std::endl;
}
