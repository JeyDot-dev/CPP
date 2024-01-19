/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:39:34 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:50:57 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
void	print_mem(std::string type, std::string* mem)
{
	std::cout << type << ": " << mem << std::endl;
}
void	print_value(std::string type, std::string str)
{
	std::cout << type << ": " << str << std::endl;
}
int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	p_str = &str;
	std::string&	r_str = str;


	print_mem("str", &str);
	print_mem("p_str", p_str);
	print_mem("r_str", &r_str);
	print_value("str", str);
	print_value("p_str", *p_str);
	print_value("r_str", r_str);
}
