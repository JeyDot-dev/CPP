/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:21 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/22 17:42:55 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

//barycentric triangle
Fixed	calc_area(Point const p1, Point const p2, Point const p3)
{
	Fixed area((
			p1.x() * (p2.y() - p3.y())
		+ 	p2.x() * (p3.y() - p1.y())
		+	p3.x() * (p1.y() - p2.y()))
		/ 	2);

	return area.toFloat() < 0 ? area * Fixed(-1) : area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed const areas[] = {	calc_area(a, b, c),	calc_area(a, b, p),
							calc_area(a, p, c), calc_area(p, b, c)};

	if (areas[1].isZero() || areas[2].isZero() || areas[3].isZero()
		|| (areas[1] + areas[2] + areas[3]) != areas[0])
		return false;
	return true;
}
