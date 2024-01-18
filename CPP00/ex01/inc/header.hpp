/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:05:36 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 18:37:25 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

enum	clean_case
{
	ADD,
	SEARCH,
	EXIT,
	NONE
};

clean_case	hash_case(std::string str);
void		print_cell(std::string s);
#endif
