/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:31:41 by jsousa-a          #+#    #+#             */
/*   Updated: 2024/01/22 17:40:44 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	if (bsp(Point(1, 1), Point(6, 12), Point(12, 1), Point(2, 4)))
		std::cout << "Is in" << std::endl;
	else
		std::cout << "Is out" << std::endl;
}
