/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:02:46 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 20:09:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef		WEAPON_HPP
# define	WEAPON_HPP
#include	<iostream>
class	Weapon
{
public:
	std::string		getType(void)		const;
	void			setType(std::string type);

	Weapon(std::string	type);
	Weapon(void);
	~Weapon(void);

private:
	std::string	_type;
};
#endif
