/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:22:43 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/22 12:41:50 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXEDFIXED_HPP
# define	FIXEDFIXED_HPP
#include <iostream>
#include <cmath>

class	Fixed
{

public:

	Fixed(void);
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(Fixed const & src);
	~Fixed(void);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);


	Fixed	&operator=(Fixed const& rhs);
	Fixed	operator+(Fixed const& rhs)	const;	
	Fixed	operator-(Fixed const& rhs) const;	
	Fixed	operator*(Fixed const& rhs) const;	
	Fixed	operator/(Fixed const& rhs) const;	

	Fixed	operator++(int);
	Fixed&	operator++(void);
	Fixed	operator--(int);
	Fixed&	operator--(void);

	bool	operator<(Fixed const& rhs)		const;	
	bool	operator>(Fixed const& rhs)		const;	
	bool	operator<=(Fixed const& rhs)	const;	
	bool	operator>=(Fixed const& rhs)	const;	
	bool	operator==(Fixed const& rhs)	const;	
	bool	operator!=(Fixed const& rhs)	const;	

//	Static
	static Fixed&		min(Fixed& fna, Fixed& fnb);
	static Fixed&		max(Fixed& fna, Fixed& fnb);
	static const Fixed&	min(Fixed const& fna, Fixed const& fnb);
	static const Fixed&	max(Fixed const& fna, Fixed const& fnb);

private:

	int					_value;
	static const int	_nb_bits;

};

std::ostream&	operator<<(std::ostream & o, Fixed const& rhs);
#endif
