/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:27 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 10:56:55 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"
#include <iostream>

// default constructor
Point::Point() : x_(0), y_(0)
{
}

// parameterized constructor
Point::Point(float x, float y) : x_(Fixed(x)), y_(Fixed(y))
{
}

// can be initailized with another Point but not assigned
Point::Point(const Point& other) : x_(other.x_), y_(other.y_)
{
}

Point::~Point()
{
}

// Point& Point::operator=(const Point& other)
// {
// 	// from C++11 we can use = delete to explicitly disallow certain operations
// 	if (this != &other)
// 	{
// 		x_ = other.x_;
// 		y_ = other.y_;
// 	}
// 	return (*this);
// }

Fixed Point::getX() const
{
	return (x_);
}
 
Fixed Point::getY() const
{
	return (y_);
}
