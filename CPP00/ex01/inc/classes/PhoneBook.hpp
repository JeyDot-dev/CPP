/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:49:48 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 16:45:50 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "header.hpp"
class	PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	add_contact(void);
	void	search(void) const;
	void	print_all(void) const;
private:
	Contact	contact[8];
};
#endif
