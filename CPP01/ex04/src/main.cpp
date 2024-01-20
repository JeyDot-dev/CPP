/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:12:50 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/20 16:43:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
bool	exit_msg(std::string reason)
{
	if (reason == "out" || reason == "in")
		std::cout << "Issue with \"" << reason << "\" file." << std::endl;
	if (reason == "ac")
		std::cout << "Usage : [file] [str_to_find] [str_replacement]" << std::endl;
	
	return false;
}

bool	open_in(char *str, std::ifstream& in, std::string& buff)
{
	std::stringstream	temp_buff;

	in.open(str);
	if (not in.is_open())
		return (exit_msg("in"));
	temp_buff << in.rdbuf();
	buff = temp_buff.str();
	in.close();
	return true;
}

bool	open_out(char *str, std::ofstream& out)
{
	out.open((std::string(str) + ".replace").c_str(),
						std::ios_base::trunc);
	if (not out.is_open())
		return(exit_msg("out"));
	return true;
}

int	main(int ac, char **av)
{
	int				i = 0;
	std::string		s1;
	std::string		buff;
	std::ifstream	in;
	std::ofstream	out;

	if (ac != 4 || !*av[1])
		return (exit_msg("ac"));
	if (!open_in(av[1], in, buff) || !open_out(av[1], out))
		return (1);
	s1 = av[2];

	while (not buff.empty())
	{
		i = buff.find(s1);
		if (static_cast<long unsigned>(i) == std::string::npos)
		{
			out << buff << std::endl;
			break ;
		}
		out << buff.substr(0, i) << av[3];
		buff.erase(0, i + s1.length());
	}
	out.close();
	return 0;
}
