/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:31:46 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/20 18:27:20 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>

class	Harl
{
public:
	void	complain(std::string level);

	Harl(void);
	~Harl(void);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};
#endif
