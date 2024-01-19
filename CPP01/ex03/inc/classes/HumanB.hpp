/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:57:58 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 19:51:04 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>

class	HumanB
{
public:
	void	equipped_info(void)		const;
	void	attack(void)	const;
	void	setWeapon(Weapon &weap);

	HumanB(std::string name);
	HumanB(void);
	~HumanB(void);

private:
	std::string	_name;
	Weapon*		_weapon;
};
#endif
