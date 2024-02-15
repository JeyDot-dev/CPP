/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:40:16 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/02/15 15:29:32 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	a("Wilson", 30);
	Form		form_a;

	std::cout << "\n" << a << "\n" << form_a << std::endl;

	try
	{
		a.signForm(form_a);
		std::cout << form_a << std::endl;
		a = Bureaucrat("Wilson_nul", 120);
		a.signForm(form_a);
		std::cout << form_a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << "\n"<<std::endl;
}
