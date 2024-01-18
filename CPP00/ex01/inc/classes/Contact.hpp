/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:39:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/18 17:01:10 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "header.hpp"
class	Contact
{
public:
	char		index;

	void	print_line(void)		const;
	void	print_contact(void)		const;
	void	create(void);
	void	copy(Contact const c);

	Contact(void);
	~Contact(void);
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};
#endif
