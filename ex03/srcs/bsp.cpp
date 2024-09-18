/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:07:29 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 16:12:49 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

static Fixed	triangleArea(Point const a, Point const b, Point const c)
{
	Fixed	dx1(b.getX() - a.getX()); // horizontal distance between a and b
	Fixed	dy1(b.getY() - a.getY()); // vertical distance between a and b
	Fixed	dx2(c.getX() - a.getX()); // horizontal distance between a and c
	Fixed	dy2(c.getY() - a.getY()); // vertical distance between a and c

	Fixed crossProduct = (dx1 * dy2) - (dx2 * dy1);

	if (crossProduct < Fixed(0))
		crossProduct = crossProduct * Fixed(-1);

	return (crossProduct / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = triangleArea(a, b, c);
    
    if (totalArea == Fixed(0))
        return (false);

    Fixed alpha = triangleArea(a, b, point);
    Fixed beta = triangleArea(a, c, point);
    Fixed gamma = triangleArea(b, c, point);

	// std::cout << "----------------------" << std::endl;
	// std::cout << "triangle: " << totalArea.toFloat() << std::endl;
	// std::cout << "alpha: " << alpha.toFloat() << std::endl;
	// std::cout << "beta: " << beta.toFloat() << std::endl;
	// std::cout << "gamma: " << gamma.toFloat() << std::endl;
	// std::cout << "----------------------" << std::endl;

	Fixed sum = alpha + beta + gamma;
	Fixed diff = (sum - totalArea).abs();
	
	Fixed Epsilon = Fixed(0.01f);

	return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0)
			&& diff < Epsilon);
}
