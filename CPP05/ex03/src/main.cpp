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
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat              a("Wilson", 5);
    Intern                  intern;
    AForm*   a_shrub = intern.makeForm("shrubbery", "Wapiti");
    AForm*   a_robot = intern.makeForm("robotomy", "Lama");
    AForm*   a_presid = intern.makeForm("presidential", "Capibara");

	std::cout << "\n" 
                << a << "\n"
                << *a_shrub << "\n"
                << *a_robot << "\n"
                << *a_presid << "\n"<< std::endl;

	try
	{
		a.signForm(*a_shrub);
        a.executeForm(*a_shrub);
	//	a.signForm(*a_robot);
        a.executeForm(*a_robot);
		a.signForm(*a_presid);
        a.executeForm(*a_presid);
		std::cout << *a_shrub << std::endl;
		a = Bureaucrat("Wilson_nul", 120);
		a.signForm(*a_shrub);
		std::cout << *a_shrub << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
	std::cout << std::endl;
    delete a_shrub;
    delete a_robot;
    delete a_presid;
}
