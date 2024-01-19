/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:10 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 20:04:14 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class	HumanA
{
public:
	void	attack(void)			const;
	void	equipped_info(void)		const;

	HumanA(std::string name, Weapon& weap);
	~HumanA(void);

private:
	std::string	_name;
	Weapon&		_weapon;
};
#endif
