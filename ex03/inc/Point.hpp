/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:00:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 10:16:47 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <Fixed.hpp>

class Point
{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);
		~Point();
		
		// we can't change the values of x_ and y_
		Point& operator=(const Point& other) = delete;
		
		Fixed getX() const;
		Fixed getY() const;
	
	private:
		const Fixed x_;
		const Fixed y_;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
