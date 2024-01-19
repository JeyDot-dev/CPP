/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:17:15 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/19 17:20:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class	Zombie
{
public:
	void			set_name(std::string name);
	std::string		get_name(void) 					const;
	void			announce(void)					const;

	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
private:
	std::string	_name;
	int			z_index;

	static int	instances;
};
#endif
