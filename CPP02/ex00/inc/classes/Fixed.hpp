/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:22:43 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/21 17:53:38 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXEDFIXED_HPP
# define	FIXEDFIXED_HPP
#include <iostream>

class	Fixed
{

public:

	Fixed(int const nb);
	Fixed(Fixed const & src);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator=(Fixed const& rhs);

	Fixed(void);
	~Fixed(void);

private:

	int					_value;
	static const int	_nb_bits;
};

#endif
