/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:51:16 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 16:13:12 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

void checkPoint(Point const& a, Point const& b, Point const& c, Point const& p) 
{
    if (bsp(a, b, c, p))
        std::cout << "(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ") is inside the triangle abc" << std::endl;
    else
        std::cout << "(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ") is outside the triangle abc" << std::endl;
}

int main(void) 
{
	std::cout << "\n       Y       c (5,5)\n";
	std::cout << "         |    /|\n";
	std::cout << "         |   / |\n";
	std::cout << "         |  /  |\n";
	std::cout << "         | /   |\n";
	std::cout << "  a(0,0) |/____|b (0,5)    \n";
	std::cout << " ---------------------------\n";
	std::cout << "       X | \n";
	std::cout << "         | \n\n";

	// triangle abc
	Point a(0, 0); 
	Point b(5, 0);
	Point c(5, 5);
	
	// points for testing
	Point p0(1, 1);
	Point p1(1, 2);
	Point p2(3, 1);
	Point p3(-5, -5);
	Point p4(1, 7);
	Point p5(3, 2);

	checkPoint(a, b, c, p0); // outside
	checkPoint(a, b, c, p1); // outside
	checkPoint(a, b, c, p2); // inside
	checkPoint(a, b, c, p3); // outside
	checkPoint(a, b, c, p4); // outside
	checkPoint(a, b, c, p5); // inside
	

	return (0);
}
